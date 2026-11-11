//GZ-J00165 遵义市第四初级中学 聂宇东
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int and1(int x,int y){
	stack<short> a;
	int r=0;
	while(x || y){
		a.push(x%2 and y%2);
		x/=2;
		y/=2;
	}
	while(!a.empty()){
		r*=2;
		r+=a.top();
		a.pop();
	}
	return r;
}
int a[200005];
int n,m,ma;
bool f[200005];
void dfs(int x,int s,int p){
	if(p==m){
		ma=max(ma,s);
		return;
	}
	if(s<ma)return;
	for(int i=x;i<n;i++){
		if(a[i]<ma)continue;
		if(!f[i]){
			f[i]=1;
			dfs(i,and1(s,a[i]),p+1);
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs(0,2147483647,0);
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

