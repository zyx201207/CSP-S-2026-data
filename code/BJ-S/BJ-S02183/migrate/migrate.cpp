#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n;
    LL d,x[200005];
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        int ans=0;
        for(int i=0;i<n;i++) cin>>x[i];
        for(int s=0;s<n-1;s+=2){
            for(int e=s+1;e<n;e++){
                int len=x[e]-x[s];
                for(int i=s;i<e;i++){
                    if(d>=len) continue;
                    else if(x[s+1]-x[s]<d) ans++;
                }
            }
        }
        cout<<ans/3;
    }
    return 0;
}
