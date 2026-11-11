#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[200005],sum,b[200005],c[200005],maxx;
void dfs(long long k){
	if(k==m+1){
		sum=a[c[1]]&a[c[2]];
		for(int i=3;i<=m;i++){
			sum=sum&a[c[i]];
		}
		if(sum>maxx)
			maxx=sum;
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				b[i]=1;
				c[k]=i;
				dfs(k+1);
				b[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<"0";
		return 0;
	}
	if(m==n){
		sum=a[1]&a[2];
		for(int i=3;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	dfs(1);
	cout<<maxx;
	return 0;
}
