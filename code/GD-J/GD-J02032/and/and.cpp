#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,m;
long long a[200005];
void dfs(long long x,int num,int cnt){
	if(num==m) {
		ans=max(ans,x);
		return;
	}
	for(int i=cnt+1;i<=n;i++){
		dfs(x&a[i],num+1,i);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1||m==n||m==n-1||n>5000){
		ans=a[n];
		for(int i=1;i<m;i++){
			ans=ans&a[n-i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i);
	}
	cout<<ans;
	
	return 0;
} 
