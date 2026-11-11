#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110000],ma=0,c,ma2=0;
void dfs(long long dep,long long s,long long x){
	if(dep==m){
		ma=max(ma,s);
		return ;
	}
	for(int i=x;i<=n;i++){
		int d=s&a[i];
		dfs(dep+1,d,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i==1){
			c=a[i];
		}else{
			c=c&a[i];
		}
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<c;
		return 0;
	}
	ma=0;
	dfs(0,111111111,1);
	cout<<ma;
	return 0;
}
