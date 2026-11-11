#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int a[N],s[N][N],p[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			s[i][j]=a[j];
			if(s[i][j]==s[i][j+1])
			s[i][j]=s[i][j+1]=0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(s[i][j]==k)
				p[k]++;
	for(int i=1;i<=m;i++)			
		cout<<p[i]<<" ";
	fclose(stdin);		
    fclose(stdout);
	return 0;
}
