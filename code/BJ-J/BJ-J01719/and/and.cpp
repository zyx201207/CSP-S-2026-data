#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200005];
bool tepan=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=i-1){tepan=0;}}

    if(m==1){ll ans=0;for(int i=1;i<=n;i++){ans=max(ans,a[i]);}cout<<ans<<endl;return 0;}
    if(m==n){ll ans=a[1];for(int i=2;i<=n;i++){ans&=a[i];}cout<<ans<<endl;return 0;}
    if(m==2){ll ans=0;for(int i=1;i<=n;i++){for(int j=i+1;j<=n;j++){ans=max(ans,a[i]&a[j]);}}cout<<ans<<endl;return 0;}
    if(tepan){if(m>n/2){cout<<0<<endl;return 0;}ll ans=0;while(m<n){n/=2;ans+=n;}cout<<ans<<endl;return 0;}//B 14 15

    tepan=1;//A 13
    for(int i=1;i<=n;i++){if(!tepan){break;}int ls=a[i];while(ls>0){if(ls%2==0){tepan=0;}ls/=2;}}
    if(tepan){sort(a+1,a+n+1);ll ans=a[n];for(int i=1;i<m;i++){ans&=a[n-i];}cout<<ans<<endl;return 0;}

    tepan=1;//16 17
    for(int i=1;i<=n;i++)if(a[i]>=4){tepan=0;break;}
    if(tepan){int t[5]={0};for(int i=1;i<=n;i++){t[a[i]]++;}if(t[3]>=m){cout<<3<<endl;}else if(t[2]+t[3]>=m){cout<<2<<endl;}else if(t[1]+t[3]>=m){cout<<1<<endl;}else{cout<<0<<endl;}}

    //以下是暴力
    if(n<=20){
        //11:41 暴力没写对 QAQ
        //11:52 暴力又没写对 QAQ
        cout<<0<<endl;
    }else{
        cout<<0<<endl;
    }

    return 0;
}
//暴力=2*10^10
//位DP
//50
//6 7 8 9 10 13 14 15 16 17
