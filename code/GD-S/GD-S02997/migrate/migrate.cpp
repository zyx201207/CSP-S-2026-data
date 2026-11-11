#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
long long x[200005];
int minn=2e9,num=0;
void dfs(int k,int now,int end)
{
	if(k==end)
	{
		if(minn>now)
		{
			minn=now;
			num=1;
			//cout<<"Minn="<<minn<<"\n";
		}
		else if(minn==now) num++;//cout<<"Num=="<<num<<"\n";;
		return ;
	}
	for(int i=k+1; i<=end; i++)
	{
		if(x[i]-x[k]>d) break;
		dfs(i,now+1,end);
	}
}
bool check(int a,int b)
{
	minn=2e9,num=0;
	dfs(a,0,b);
	//cout<<"\n\n";
	if(num==2) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1; i<=n; i++)
		{
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				ans+=check(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
