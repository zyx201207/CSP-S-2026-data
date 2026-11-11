#include<bits/stdc++.h>

using namespace std;

long long a,s,d,q[200005];
void dfs(long long z,long long x,long long c)
{
	if(z<=d)
	return ;
	if(x==0)
	{
		d=z;
		return ;
	}
	for(int dfsz=c;dfsz<=a-x+1;dfsz++)
	{
		dfs((z&q[dfsz]),x-1,dfsz+1);
	}
}
bool tpb()
{
	long long z=a;
	while(z>1)
	{
		if(z%2==1)
		return 0;
		z/=2;
	}
	for(int z=1;z<=a;z++)
	{
		if(q[z]!=z-1)
		{
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>a>>s;
	
	for(int z=1;z<=a;z++)
	{
		cin>>q[z];
	}
	if(tpb()==1)
	{
		cout<<q[a-s+1];
	}
	else
	{
		for(int z=1;z<=a-s+1;z++)
		{
			dfs(q[z],s-1,z+1);
		}
		cout<<d;
	}
	
	return 0;
} 
