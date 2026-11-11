#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],v[200005];
long long maxn=-1,num;
void dfs(int x){
	if(x>=m){
		maxn=max(maxn,num);
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			num=num&a[i];
			dfs(x+1);
			v[i]=0;
			num=a[i-1];
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	dfs(1);
	cout <<maxn;
	return 0;
}
