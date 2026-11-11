#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> t,a;
unordered_map<int,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	t.assign(m+1,0);
	a.assign(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int> G(n+1,0);
	int tail=0;
	for(int i=n;i>=1;i--){
		if(mp.count(a[i])&&G[mp[a[i]]]==a[i]&&mp[a[i]]<=tail)tail=mp[a[i]];
		else G[++tail]=a[i],mp[a[i]]=tail;
		for(int j=1;j<=tail;j++)t[G[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	pair<int,int> a={123456,456123};
	auto[x,y]=a;
	cout<<x<<" "<<y<<"\m";
	return 0;
} 
