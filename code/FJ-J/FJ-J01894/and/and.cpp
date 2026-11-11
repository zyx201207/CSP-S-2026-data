#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],ans=0;

void dfs(int k,int num,int sum){
	if(k>n){
		if(num==m) ans=max(ans,sum);
		return;
	} 
	dfs(k+1,num+1,sum&a[k]);
	dfs(k+1,num,sum);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn=-1,res=(1<<30)-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		res&=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<res;
		return 0;
	}
	if(m==2){
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=max(s,a[i]&a[j]); 
			}
		}
		cout<<s;
		return 0;
	}
	if(n<=20){
		dfs(1,0,(1<<30)-1);
		cout<<ans;
		return 0;
	} 
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}

