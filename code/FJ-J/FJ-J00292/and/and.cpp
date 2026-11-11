#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=0,m=0,ans=0,tf=0;
ll a[200005];
ll p[40];
vector<ll> v[40];
int vis[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//system("diff a.in b.in");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,k=0,id=0;i<=n;i++){
		k=a[i],id=0;
		while(k){
			if(k%2)v[id].push_back(i);
			id++,k/=2;
		}
	}
	for(int i=30;i>=0;i--){
		if(v[i].size()>=m){
			for(int j=0;j<v[i].size();j++)vis[v[i][j]]=1;
			break;
		}
	}
	for(int i=30;i>=0;i--){
		for(int j=0;j<v[i].size();j++)if(vis[v[i][j]])p[i]++;
		//cout<<p[i]<<'\n';
		if(p[i]>=m){
			ll k=0;
			for(int j=0;j<v[i].size();j++)if(vis[v[i][j]])vis[v[i][j]]=2,k=a[v[i][j]];
			for(int j=1;j<=n;j++){
				if(vis[j]==2)vis[j]=1,k&=a[j];
				else vis[j]=0;
			}
			if(ans<k)ans=k;
		}
		//cout<<v[i].size()<<' ';
	}
	//cout<<endl;
	cout<<ans;
	return 0;
}


