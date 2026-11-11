#include<iostream>
#include<algorithm>
using namespace std;
constexpr int N=2e5+5;
int a[N],n,m,ans=0;
// test 1-5
bool f[30];
void work1(int i,int cnt){
    if(cnt>m) return;
    if(i>n){
        if(cnt!=m) return;
        int t=(1<<30)-1;
        for(int j=1;j<=n;j++) if(f[j]) t&=a[j];
        ans=max(ans,t);
        return;
    }
    f[i]=1;
    work1(i+1,cnt+1);
    f[i]=0;
    work1(i+1,cnt);
}
// test 11-20
bool cmp(const int& x,const int& y){
    int t1=__builtin_popcount(x),t2=__builtin_popcount(y);
    if(t1==t2) return x>y;
    if(t1>t2) return true;
    return false;
}
void work2(){
    sort(a+1,a+n+1,cmp);
    ans=(1<<30)-1;
    for(int i=1;i<=m;i++) ans&=a[i];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m;
    bool b=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b&=(!(a[i]-i+1));
    }
    if(n<=20) work1(1,0);
    else if(n<=2000){
        if(m==1) ans=*max_element(a+1,a+n+1);
        else if(m==n){
            ans=(1<<30)-1;
            for(int i=1;i<=n;i++) ans&=a[i];
        }
        else if(m==2){
            for(int i=2;i<=n;i++){
                for(int j=1;j<i;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
    }
    else if(b) ans=n-m;
    else work2();
    // work2();
    cout<<ans<<'\n';
    return 0;
}