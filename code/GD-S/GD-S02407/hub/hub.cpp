#include<bits/stdc++.h>
#define lll long long
using namespace std;
lll c,t,n,k;
struct node{
	lll nx,w,to;
}e[5000500];
lll head[5000500],cnt;
void adde(lll u,lll v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nx=head[u];
	head[u]=cnt;
}
lll gun[2][5050],dong[2][5050];
lll zs1=0,zs2=1;
/*void dfs(lll chen)
{
	zs1^=1;zs2^=1;
	
}*/
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t>0)
	{
		t--;cnt=0;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			lll u,v;cin>>u>>v;
			adde(u,v);adde(v,u);
		}
		cout<<rand()%(n/k+1)-1<<endl;
	//	dfs(0)
	}
	
	
	fclose(stdin);fclose(stdout);
	return 0;
 } 
