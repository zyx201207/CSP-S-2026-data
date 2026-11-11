#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+5;
const int N=500;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ans=0;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(M),k(N);
	vector<vector<int>> a(N,vector<int>(M)),t(N,vector<int>(M));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(int i=1;i<=m;i++){
			int m=0;
			for(int j=1;j<=k[i];j++){
				
				for(int jj=j+1;jj<=k[i];jj++) if(a[i][j]==x&&a[i][jj]==y){m=1;break;}
				if(!m){
					ans+=t[1][1];
					m=1;
				}else break;
			}
			if(m){
				break;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

