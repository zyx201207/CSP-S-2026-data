#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
const int N=5e5+5;

ll c,n,m,d,q,k,x,y;
ll a[505][1005],t[505][1005];
ll w[505];
ll ans=0x3f3f3f3f3f3f3f3f;
vector<ll>vr[505];
bool f[505]; 


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen("subway4.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
		cin>>w[i];
		
	cin>>k;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			vr[a[i][j]].push_back(i);
	}
					
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		fill(f,f+505,0);
		if(x==y){
			cout<<0;
			continue;
		}
		queue<pair<ll,ll>>qe;
		qe.push({x,w[i]});
		f[x]=1;
		while(!qe.empty()){
			ll ft=qe.front().first;
			ll sc=qe.front().second;
			
			qe.pop();
			ll id1=vr[ft][0],id2=vr[ft][1];
			ll w1=t[id1][1]+t[id1][2];
			ll w2=t[id2][1]+t[id2][2];
			ll u1=a[id1][1]==ft?a[id1][2]:a[id1][1];
			ll u2=a[id2][1]==ft?a[id2][2]:a[id2][1];
			qe.push({u1,sc+w1});
			qe.push({u2,w2});
			
			if(ft==y){
				ans=min(ans,sc+w[y]);
			}
		}
		cout<<ans;
	}
	return 0;
	
	
}
