#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
long long t,n,d,x[N],p[N][N],ans,c;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long ans=0;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c>=1&&c<=2){
            cout<<x[n]/d+1;
        }
        else if(c>=11&&c<=12){
            long long dd=x[2]-x[1];
            for(int i=1;i<d/dd;i++)
                ans+=(n-(i+d/dd)+1);
            cout<<ans<<"\n";
            continue ;
        }
        else if(c>=13&&c<=14){
            cout<<x[n]/d;
        }
    }

    return 0;
}

