#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t;
long long by[500005];
long long lc[505][505];
vector<int>jg[500005];
vector<int>sj[500005];
vector<int>jh[505];
void cbgt(){
	for(int i=1;i<=t;i++){
		for(int j=0;j<jg[i].size();j++){
			for(int k=0;k<jg[i].size();k++){
				if(j!=k){
					long long f=sj[i][j]+sj[i][k];
					lc[jg[i][j]][jg[i][k]]=min(lc[jg[i][j]][jg[i][k]],f);
					lc[jg[i][k]][jg[i][j]]=lc[jg[i][j]][jg[i][k]];
				}else lc[jg[i][j]][jg[i][k]]=0;
			}
		}
	}
}
void gt(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				lc[i][j]=min(lc[i][j],lc[i][k]+lc[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>by[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) lc[i][j]=1e15;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int l,r;
			cin>>l>>r;
			t=max(t,l);
			jg[l].push_back(i);
			sj[l].push_back(r);
			jh[i].push_back(l);
			jh[i].push_back(r);
		}
	}
	cbgt();
	gt();
	while(q--){
		int l,r;
		cin>>l>>r;
		long long t=1e15;
		for(int i=0;i<jg[l].size();i++){
			for(int j=0;j<jg[r].size();j++){
				t=min(t,lc[jg[l][i]][jg[r][j]]+sj[l][i]+sj[r][j]);
			}
		}
		cout<<t+by[l]+by[r]<<"\n";
	}
	return 0;
}
