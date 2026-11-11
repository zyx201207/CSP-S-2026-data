#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005],b[200005];
long long ans=0;

bool vis[200005];
void dfs(long long pos){
	if(pos>=m){
		long long an=b[0];
		for(long long i=1;i<m;i++){
			an=(an&b[i]);
		}
		
		if(an>ans){
			ans=an;
		}
	}
	
	for(long long i=0;i<n;i++){
		if(!vis[i]){
			b[pos]=a[i];
			vis[i]=true;
			dfs(pos+1);
			vis[i]=false;
		}
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	
	dfs(0);
	cout<<ans;
	return 0;
}
