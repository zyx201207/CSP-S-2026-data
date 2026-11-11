#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxx;
long long a[200005];
bool vis[200005];
void dfs(long long k,int sub,int len){
	if(len==m){
		maxx=max(maxx,k);
	}
	for(int i=sub+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(k&a[i],i,len+1);
			vis[i]=0;
		}
	}
}
long long k1,k2,k3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<i<<endl;
		if(a[i]>k1) k1=a[i];
		for(int j=1;j<i;j++){
			k2=max(k2,(a[i]&a[j]));
		}
		if(i==1) k3=a[i];
		else k3&=a[i];
	}
	if(m==1) cout<<k1;
	else if(m==2) cout<<k2;
	else if(m==n) cout<<k3;
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,(k3&a[i]));
		}
		cout<<maxx;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(a[i],i,1);
			vis[i]=0;
		}
		cout<<maxx;
	}else{
		sort(a+1,a+1+n);
		maxx=a[n];
		for(int i=n;i>n-m;i--){
			maxx&=a[i];
		}
		cout<<maxx;
	}
	return 0;
} 
