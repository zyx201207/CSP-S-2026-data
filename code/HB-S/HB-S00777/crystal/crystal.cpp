#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    long long n,m,sum=0,ans=0,f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-f);
        while(sum>m)sum-=a[i]-a[f++];
        if(i-f+1>ans)ans=i-f+1;
    }
    cout<<ans<<'\n';
    return ( 0 - 0 );
}
//luogu's P11690 , P11691 , and P11682 is really great!!!
//play BA(Blue Archive) just now!!!
//and adofai(A dance of fire and ice)!!!
//yasashii yukachan desu!!!
//yasashii noachan desu!!!
//kawaii hinachan desu!!!
//kawaii hoshinochan desu!!!
//kawaii shirakochan desu!!!
//kawaii azusachan desu!!!
//CCF,I want to AK IOI!