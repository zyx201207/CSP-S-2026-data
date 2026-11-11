#include <bits/stdc++.h>
using namespace std;
int c,n,m,k[505],di,qi;
long long w[500005],nl[503][503],d[503][503],ix,iy,px,ypp,ans;
bool hg[503][503];
vector <long long> nw[505],wn[500005][2];
pair <long long,int> inn;
priority_queue < pair<long long,int> > q;
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>di>>qi;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++) {
		cin>>k[i];
		for (int j=1;j<=k[i];j++) {
			cin>>ix>>iy;
			for (int ij=0;ij<wn[ix][0].size();ij++) {
				px=wn[ix][0][ij];
				ypp=wn[ix][1][ij];
				if (nl[i][px]==0) {
					nl[i][px]=iy+ypp;
					nl[px][i]=iy+ypp;
					nw[i].push_back(px);
					nw[px].push_back(i);
				}
				else if (nl[i][px]>(iy+ypp)) {
					nl[i][px]=iy+ypp;
					nl[px][i]=iy+ypp;
				}
			}
			wn[ix][0].push_back(i);
			wn[ix][1].push_back(iy);
		}
	}
	for (int i=1;i<=n;i++) {
		inn.first=0;
		inn.second=i;
		q.push(inn);
		while (!q.empty()) {
			inn=q.top();
			q.pop();
			ix=inn.second;
			if (hg[i][ix]) continue;
			hg[i][ix]=true;
			iy=inn.first;
			for (int j=0;j<nw[ix].size();j++) {
				px=nw[ix][j];
				if (px==i||((d[i][ix]+nl[ix][px])>=d[i][px]&&d[i][px]!=0)) continue;
				ypp=d[i][ix]+nl[ix][px];
//				if (i==1) cout<<"_"<<px<<" "<<nl[ix][px]<<"\n";
				d[i][px]=ypp;
				d[px][i]=ypp;
				inn.first=ypp;
				inn.second=px;
				q.push(inn);
			}
		}
	}
//	for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++) cout<<nl[i][j]<<" "<<i<<" "<<j<<"\n";
	while (qi--) {
		ans=-1;
		cin>>ix>>iy;
		for (int i=0;i<wn[ix][0].size();i++) {
			for (int j=0;j<wn[iy][0].size();j++) {
				if (ans==-1) ans=wn[ix][1][i]+wn[iy][1][j]+d[wn[ix][0][i]][wn[iy][0][j]];
				else ans=min(ans,wn[ix][1][i]+wn[iy][1][j]+d[wn[ix][0][i]][wn[iy][0][j]]);
			}
		}
		cout<<(ans+w[ix]+w[iy])<<"\n";
	}
	return 0;
}

