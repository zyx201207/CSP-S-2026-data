#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w[40],mx,d[40],ans,l;
vector<int>e[40];
vector<int>q;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	w[0]=1;
	for(int i=1;i<=30;i++)w[i]=2*w[i-1];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int o,u=0;
		cin>>o;
		int y=o;
		while(o){
			u++;
			if(o&1){
				d[u]++;
				e[u].push_back(y);
			}
			o>>=1;
		}
		mx=max(mx,u); 
	}
	for(int i=mx;i>=1;i--){
		if(d[i]>=m){
			l=i;
			for(int j:e[i])q.push_back(j);
			ans+=w[i-1];
			break;
		}
	}
	for(int i=1;i<=mx;i++){
		e[i].clear();d[i]=0;
	}
	while(!q.empty()){
		mx=0;
		for(int o:q){
			int u=0,y=o;
			while(o){
				u++;
				if(o&1){
					d[u]++;
					e[u].push_back(y);
				}
				o>>=1;
			}
			mx=max(mx,u);
		}
		q.clear();
		for(int i=l-1;i>=1;i--){
			if(d[i]>=m){
				l=i;
				for(int j:e[i])q.push_back(j);
				ans+=w[i-1];
				break;
			}
		}
		for(int i=1;i<=mx;i++){
			e[i].clear();d[i]=0;
		}
	}
	cout<<ans;
	return 0;
}/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
