#include<iostream>
#include<cstring>
using namespace std;
constexpr int N=5e5+5,M=3e5+5;
int a[N],n,m;
int ans[M],q[N],top=0;
bool f[M];
// for A
void work1(){
    for(int i=1;i<=n;i++) ans[a[i]]++;
    for(int i=1;i<=m;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m;
    bool A=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        A&=(a[i]>=a[i-1]);
    }
    if(A) return work1(),0;
    for(int j=1;j<=n;j++){
        top=0;
        for(int i=j;i<=n;i++){
            if(!top) q[++top]=a[i];
            else{
                int p=0;
                for(int l=1;l<=top;l++){
                    if(q[l]==a[i]){
                        p=l;
                        break;
                    }
                }
                if(!p) q[++top]=a[i];
                else top=p;
            }
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=top;i++) f[q[i]]=true;
        for(int i=1;i<=m;i++) ans[i]+=f[i]; 
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}