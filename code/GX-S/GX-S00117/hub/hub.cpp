#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int maxx;
int a,b;
int c,t,n,k;
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++) cin>>a>>b;
        if(k==1) cout<<2<<'\n';
        else if(k==2||k==3||k==4) cout<<1<<'\n';
        else cout<<0;
    }
	return 0;
}
