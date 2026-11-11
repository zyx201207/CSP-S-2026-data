#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,L=0;
	cin>>n>>m;
	int l[n],f[m+1],S[m+1],P[m];
	for(int i=n;i--;) scanf("%d",l+i);
	for(int i=1;i<=m;i++)
	{
		f[i]=0;
	}
	f[l[0]]=-1;
	P[0]=l[0];
	S[l[0]]=1;
	for(int i=1;i<n;i++)
	{
		if(f[l[i]]==0)
		{
			f[l[i]]=l[i-1];
			S[l[i]]=1;
			P[++L]=l[i];
			printf("Added Son:%d\n",l[i]);
		}
		else
		{
			S[l[i]]++;
			printf("Added Score:%d\n",l[i]);
		}
	}
	for(int i=m;--i;) S[f[P[i]]]+=S[P[i]];
	for(int i=1;i<=m;i++) printf("%d ",S[i]);
	return 0;
}
