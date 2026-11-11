//¿ÓºŒ‘∆ GZ-S00252 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second 
#define pb push_back
#define pq priority_queue
const int N=4E5+10;
int c,n,m,d,q,w[N],a[505][N],k[N],ans[N],t[505][N];
vector<pair<int,int> >v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j]>>t[i][j];
			if(j>1){
				v[a[i][j-1]].push_back({a[i][j],i});
				v[a[i][j]].push_back({a[i][j-1],i});
			}
		}
	}
	
	return 0;
}
