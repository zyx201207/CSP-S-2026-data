#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m,cnt[35];
bitset<N>bit[35];
void solve1(){
    int maxn=0;
    for(int i=1;i<=n;i++)maxn=max(a[i],maxn);
    cout<<maxn<<"\n";
}
void solve2(){
    int ans=a[1];
    for(int i=2;i<=n;i++)ans=(ans&a[i]);
    cout<<ans<<"\n";
}
void solve3(){
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,(a[i]&a[j]));
    cout<<ans<<"\n";
}
void solve0(){
    for(int i=0;i<30;i++){
        for(int j=1;j<=n;j++){
            if((a[j]>>i)&1){
                cnt[i]++;
                bit[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=29;i>=0;i--){
        if(cnt[i]>=m){
            bitset<N>st;
            st.reset();st|=bit[i];
            ans+=(1<<i);
            int t=i-1;
            for(int j=t;j>=0;j--){
                if((st&bit[j]).count()>=m){
                    ans+=(1<<j);
                    st&=bit[j];
                }
            }
            break;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){solve1();return 0;}
    if(m==n){solve2();return 0;}
    if(m==2&&n<=2000){solve3();return 0;}
    solve0();
    return 0;
}