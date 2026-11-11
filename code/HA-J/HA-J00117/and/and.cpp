#include <bits/stdc++.h>
using namespace std;
#define ld long long
ld arr[200005],gc[100005],jg[20000005];
ld m,n,step=0;
bool v[200005];
void hs(ld s)
{
	if(s>=m)
	{
		jg[step]=(gc[0]&gc[1]);
		for(int k=2;k<s;k++)
		{
			jg[step]=(jg[step]&gc[k]);
		}
		step++;
		return ;
	}
	for(int j=0;j<n;j++)
	{
		if(v[j]==0)
		{
			v[j]=1;
			gc[s]=arr[j];
			hs(s+1);
			v[j]=0;
		}
	}
	return ;
}
int main(int argc, char** argv)
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ld i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	hs(0);
	ld MAX=0;
	for(int i=0;i<step;i++)
	{
		if(MAX<jg[i])
		{
			MAX=jg[i];
		}
	}
	cout<<MAX;
	return 0;
}
