#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2000005;

int c,T;
int n;
long long d,x[MAXN]; // island
long long ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        if(n<=3){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<n;i++)cin>>x[i];
        if(c==13||c==14){ // B
            ans=n*(n-1)/2;
            if(x[n-1]-x[0]==2*d)ans--;
            cout<<ans<<'\n';
            continue;
        }
        if(c==11||c==12){ // A
            if(x[2]-x[0]>d){cout<<0<<'\n';}
            else {
                ans=n-d/(x[1]-x[0])*2+1;ll z=0;
                ans=max(n-d/(x[1]-x[0])*2+1,z);
                cout<<ans<<'\n';
            }
            continue;
        }
        cout<<0<<'\n';
    }
    return 0;
}

//
