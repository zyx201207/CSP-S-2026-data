#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010];

long long func(int x,int y){
	long long ans=0;
	if(y>=m){
		return a[x];
	}
	for(int i=x+1;i<=n;i++){
		ans=max(ans,((a[x])&(func(i,y+1))));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	long long ans=0;
	for(int i=1;i<=n-m+1;i++){
		ans=max(ans,func(i,1));
	}
	cout<<ans;
	
	return 0;
}
