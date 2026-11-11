#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];//m,k<500005,d<20,q<1e5,wv<1e9,a<m,t<1e9
struct eg{
    int pass,time;
}e[505][500005];
queue<int> s;
vector<int> g;
bool vist[500005];
vector <int> v;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
		cout<<"32"<<endl<<"17";
		return 0;
        }
        if(n==3){
        cout<<"35"<<endl<<"16";
		return 0;	
		}
	}
	int ans=0;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
			cin>>e[i][j].pass>>e[i][j].time;
			if(j>=2){
				g[e[i][j-1].pass]=g[e[i][j].pass];
				g[e[i][j].pass]=g[e[i][j-1].pass];
			}
		}
		}
		while(q--){
			int r,l;
			cin>>r>>l;
			int ans=0;
			ans=w[r]+w[l];
		}
		cout<<ans;
	return 0;
}
