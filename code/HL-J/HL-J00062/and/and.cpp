#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int bj[N];
long long a[N],mxx;
void dfs(int m,int u,int ans){
	if(u>m){
		if(ans>mxx) mxx=ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			bj[i]=1;
			int op=ans;
			if(u==1) op=a[i];
			else op=op&a[i];
			dfs(m,u+1,op);
			bj[i]=0;
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
	}
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mx) mx=a[i];
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long sum;
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if((a[i]&a[j])>=mx) mx=(a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	dfs(m,1,0);
	cout<<mxx;
}