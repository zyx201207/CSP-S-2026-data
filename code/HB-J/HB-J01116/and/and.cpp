#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,mx;
int a[N];
void dfs(int op,int save ,int num){
	if(num>m){
		mx=max(mx,save);
		return ;
	}
	if(op>n)return ;
	dfs(op+1,save,num);
	int t=save and a[op];
	dfs(op+1,t,num+1);
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-m;i++)dfs(i+1,a[i],1);
	cout<<mx;
	return 0;
}
