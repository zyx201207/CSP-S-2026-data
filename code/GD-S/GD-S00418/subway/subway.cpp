#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct qwe{
	int t,a;
}v[500005];
int w[500005];
int daan(int ll,int rr){
	int ans=0;
	ans=w[ll]+v[ll].t+w[rr]+v[rr].t+v[ll].a+v[rr].a;
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>v[i].t>>v[i].a;
		}
	}
	
	for(int i=1;i<=q;i++){
		int ll,rr;
		cin>>ll>>rr;
		cout<<daan(ll,rr)<<"\n";
	}
	return 0;
}
