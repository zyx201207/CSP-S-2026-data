#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct XX{
	ll x,y,z,p;
}b[501];
ll cmp(XX a,XX b){
	if(a.x!=b.x)return a.x<b.x;
	else if(a.x==b.x&&a.y!=b.y)return a.y<b.y;
	else if(a.x==b.x&&a.y==b.y&&a.z!=b.z)return a.z<b.z;
	else if(a.x==b.x&&a.y==b.y&&a.z==b.z&&a.p!=b.p)return a.p<b.p;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    ll w[m];
	for(int i=0;i<m;i++){
    	cin>>w[i]; 
	}
	for(int i=0;i<n;i++){
    	ll a;
		cin>>a;
		cin>>b[i].x>>b[i].y>>b[i].z>>b[i].p;
	}
	sort(b,b+n,cmp);
	for(int i=0;i<q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		ans+=w[x-1];
		ans+=w[y-1];
		for(int j=0;j<n;j++){
			if(b[j].x==x&&b[j].z==y){
				ans+=b[j].y;
				ans+=b[j].p;
			}
		}
		cout<<ans<<endl;
	}
}