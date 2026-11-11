#include<bits/stdc++.h>
using namespace std;

const int N1=2e6+5,N2=5e3+5;
int c,t,n;
long long d,x[N1];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>c>>t;
    if(c>=11&&c<=12){
        while(t--){
            cin>>n>>d;
            for(int i = 1;i<=n;i++) cin>>x[i];
            long long c = x[2]-x[1];
            c/=d;
            n-=2;
            int num=n;
            n/=c;
            long long ans=0;
            for(int i = 1;i<=c;i++){
                ans+=num-n*i;
            }
            cout<<ans<<'\n';
        }
    }
    
    return 0;
}