#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dfs(int d,int b){
	if(d>=m) return b;
	int l,ma=0; 
	for(int i=1;i<=n;i++){
		if(a[i]==0) continue;
		l=a[i];
		a[i]=0;
		ma=max(dfs(d+1,b&l),ma);
		a[i]=l;
	}return ma;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
    cout<<dfs(0,-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

