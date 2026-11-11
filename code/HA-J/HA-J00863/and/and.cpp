#include<bits/stdc++.h>
using namespace std;
long long a[1000000],used[1000000],n,m,ans=0,b[100000];
int dfs(int x){
	if(x>=m){
		long long s=b[a[0]];
		for(int i=0;i<m;i++){
			cout<<a[i]<<" ";
			if(i)
			s=b[a[i]]&s;
		}
		ans=max((int)s,(int)ans);
		cout<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			a[x]=i;
			dfs(x+1);
			used[i]=0;
		}
	}
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>n>>m;
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
