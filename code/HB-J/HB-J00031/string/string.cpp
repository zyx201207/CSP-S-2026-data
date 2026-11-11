#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct node{
	long long m;
	char c;
}a[200005];
void dfs(int x,int y){
	if(x>=y)return;
	long long t=min(a[x].m,a[y].m);
	if(a[x].c!=a[y].c)sum+=t;
	if(a[x].m==t)x++;
	else a[x].m-=t;
	if(a[y].m==t)y--;
	else a[y].m-=t;
	dfs(x,y);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].m>>a[i].c;
	dfs(1,n);
	cout<<sum;
	return 0;
}
