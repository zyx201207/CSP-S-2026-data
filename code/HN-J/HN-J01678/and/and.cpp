#include<bits/stdc++.h>
using namespace std;
long long s[31][200005],a,sum;
int n,t[31],m,maxx;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		int u=1;
		while(a>0)
		{
			s[u][i]=a%2;
			t[u]=a%2;
			a/=2;
			u++;
			maxx=max(maxx,u);
		} 
	}
	for(int i=maxx;i>0;i--)
	{
		if(t[i]>m)
		{
			int se=1;
			for(int j=1;j<=i;j++)
			{
				se*=2;
			}
			sum+=se;
		}
	}
	cout<<sum;
	return 0;
}
