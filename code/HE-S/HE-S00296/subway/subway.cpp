#include <bits/stdc++.h>
using namespace std;
const int N=405;
struct s{
	int a;
	int t;
};
bool cmp(int a,int b){
	return a<b;
}
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector <int> g;
	int c,n,m,d,q;
	s x[N][505];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>x[i][j].a>>x[i][j].t;
		}
	}for(int z=0;z<q;z++){
		int r,l;
		cin>>r>>l;
		int res=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<201;j++){
				if(r==x[i][j].a){
					int ans=w[r]+w[l]+x[i][j].t+x[i][j+1].t;
					res=1;
					g.push_back(ans);
					break;
				}
			}if(res==1){
				break;
			}
		}sort(g.begin(),g.end(),cmp);
		cout<<g[0];
	}return 0;
} 
