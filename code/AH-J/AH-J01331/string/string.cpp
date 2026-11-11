#include<bits/stdc++.h>
using namespace std;
int n,j,c[20005];
long long sum;
char b[20005];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);

cin>>n;
if(n==1)
{
cout<<"0";
return 0;
}
for(int s=0;s<=n;s++)
{
cin>>c[s]>>b[s];
}
for(int s=0;s<=n;s++)
{
sum+=c[s];
}
char g[sum];
for(int s=0;s<=sum;s++)
{
for(int w=0;w<=n;w++)
	{
	for(int p=0;p<=c[s];p++)
	{
	g[s]=b[w];
	}
}
for(int y=0;y<=sum+1/2;y++)
{
if(g[y]!=g[sum-y])
{
g[y]=g[sum-y];
j++;
}
}
cout<<j;
}
}

