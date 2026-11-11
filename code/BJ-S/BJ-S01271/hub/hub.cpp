#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,m;
    int q,w;
    cin>>n>>m;
    int a,b;

    int ans=0;
    for(int i=1;i<=m;i++){
            ans=0;
         cin>>a>>b;
            for(int j=1;j<=a-1;j++){
        cin>>q>>w;
    ans+=q;
        ans+=w;
        ans=ans%(a+2);
    }
        if(ans==0){
            cout<<1<<endl;
        }
        else
            cout<<ans<<endl;

    }

    return 0;
}

