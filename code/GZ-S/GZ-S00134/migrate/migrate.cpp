//GZ-S00134,刘雨航,北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
const int BIRD=2000006;
long long a[BIRD],b[BIRD],cc[BIRD],ans;
void dfs(int s,int i,int jt)
{
	if(i==n){
		b[s]++;
		cc[s]=jt;
	}
	for(int j=i+1;j<=n;j++)
	{
		if(abs(a[i]-a[j])<=d)dfs(s,j,jt+1);
		else break;
	}return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)dfs(i,1,0);
		for(int i=1;i<n;i++)
		{
			if(b[i]==2)ans++;
		}
		cout<<ans;
	}
	return 0;
}
