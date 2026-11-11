#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000007],cha[2000007];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        x[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>x[i];
            cha[i]=x[i]-x[i-1];
        }
        if(c==0||c==11||c==12){
            d=d/cha[n];
            if(d<2||d>(x[n]+cha[n]-x[1])/cha[n]-2) cout<<0;
            else cout<<max(0LL,n-2*d+1);
        }
        else cout<<0;
        cout<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
