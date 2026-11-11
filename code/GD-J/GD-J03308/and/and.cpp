#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[200005],v[200005],t[200005];
int max_a;
int ans;
int a1,a2;

void dfs(int x,int sum){
	if(x==m){
		ans=max(ans,sum);
		return;
	}
	if(x==0){
		for(int i=1;i<=n;i++){
			sum=a[i];
			v[i]=1;
			dfs(x+1,sum);
			v[i]=0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int f=sum;
			if(v[i]==0){
			sum=sum&a[i];
			v[i]=1;
			dfs(x+1,sum);
			sum=f;
			v[i]=0;
		}
		}
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_a=max(max_a,a[i]);
	}
	if(m==n){
		cnt=a[1];
		for(int i=i;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
		}
		if(m==1){
			cout<<max_a;
		}
		if(n<=20){
		dfs(0,0);
		cout<<ans;
		return 0;
		}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
			ans=max(ans,a[i]&a[j]);
		}
		}
		cout<<ans;
	return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
			ans=max(ans,a[i]&a[j]);
		}
		}
			cout<<ans;
	return 0;
	}
	
	cout<<ans;
	return 0;
} 
