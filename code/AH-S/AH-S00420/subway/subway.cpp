#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,c,n,m,d,p,w[1000010];
ll a[1000010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[x]+=y;
        }
    }
    for(int i=1;i<=p;i++){
        ll ans=0;
        ll xx,yy;
        cin>>xx>>yy;
        ans+=w[xx]+w[yy];
        for(int j=xx;j<=yy;j++){
            ans+=a[j];
        }
        cout<<ans;
    }
	return 0;
}
