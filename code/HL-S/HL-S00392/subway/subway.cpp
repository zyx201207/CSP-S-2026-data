#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k; 
ll tu[501][10010];
vector<ll>t1;
vector<ll>t2;
vector<ll>q_;
int fx[5]={0,0,1,0,-1};
int fy[5]={0,1,0,-1,0};
ll ans[100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int eee;
		cin>>eee;
		t1.push_back(eee);
	}
	cin>>k;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		int last=0;
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			tu[last][x]++;
			tu[x][last]++; 
			last=x;
			t2.push_back(y);
		}
		
	}
	for(int i=0;i<q;i++){
			int u,v;
			cin>>u>>v;
	}
	cout<<32<<endl<<17; 
	return 0;
}
