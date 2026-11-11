#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int v[500005];
int t[5005][50005];
vector<int> asd[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>v[j]>>t[i][j];
			asd[i+1].push_back(v[j]);
		}
	}
	
	for(int i=0;i<q;i++){
		int ans=0;
		int x,y;
		cin>>x>>y;
		ans+=w[x-1];
		ans+=w[y-1];
		ans+=t[x-1][x-1];
		for(int i=x;i<y-1;i++){
			ans+=t[i-1][i]+t[i][i];
		}
		ans+=t[y-2][i];
		cout<<ans<<"\n";
	}
}
