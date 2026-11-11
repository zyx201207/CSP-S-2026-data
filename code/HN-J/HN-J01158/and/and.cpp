#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200001],ans;
struct node{
	int ans,len,i;
}; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}	
		cout<<ans;
	}
	else if(n>=200000){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else{
		queue<node> q;
		q.push({(1<<31)-1,0,0});
		while(!q.empty()){
			int u=q.front().ans,len=q.front().len,x=q.front().i;
//			cout<<u<<" "<<len<<" "<<x<<endl;
			q.pop();
			if(len==m){
				ans=max(ans,u);
				continue;
			}
			if(x==n+1){
				continue;
			}
			q.push({u,len,x+1});
			q.push({(u&a[x]),len+1,x+1});
		}
		cout<<ans;
		
	}
	return 0;
}
