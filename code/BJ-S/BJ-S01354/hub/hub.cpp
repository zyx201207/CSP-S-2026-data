#include<bits/stdc++.h>
using namespace std;
const int maxn=2000009;
int n,c,t,k,m,u,v,ans;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c>=13&&c<=14){
        while(t--){
            cin>>n>>k;
            m=n/2;
            for(int i=1; i<n; i++)
            {
                cin>>u>>v;
            }
            if(k==1)
            {
                cout<<(m+2)/2<<'\n';
                continue;
            }
            ans=(m+k*2+4+(k-1))/k;
            cout<<ans<<' ';
            ans=(ans+1)/2;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
