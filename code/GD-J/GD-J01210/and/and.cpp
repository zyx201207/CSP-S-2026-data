#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,m;
long long a[200005],sum;
void dfs(int l,long long x,int id){
	if(l==m){
		sum=max(sum,x);
		return;
	}
	for(int i=l+1;i<=n;i++){
		if(x&a[i]){
			dfs(l+1,x&a[i],i);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	long long x=a[1],ma=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		x=a[i]&x;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)dfs(1,a[i],i);
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
} 
