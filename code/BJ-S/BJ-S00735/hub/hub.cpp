#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,a;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<n*2-2;i++) cin>>a;
        n=(n+1)/2;
        cout<<(n-k)/4+1<<'\n';
    }

    return 0;
}
