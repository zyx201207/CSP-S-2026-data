#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50005],a[505][50005],tt[505][50005],p[50005];
struct node{
	int na,ww;
};
vector<node> mp[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int t=0;
		cin>>t;
		for(int j=1;j<=t;j++){
		    cin>>a[i][j]>>tt[i][j];	
		} 
		for(int i=1;i<t;i++){
			for(int j=i+1;j<=t;j++){
				mp[i].push_back({j,0});
			}
		}
		
	}
	return 0;
}

