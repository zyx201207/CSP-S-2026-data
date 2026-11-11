#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],t[N],c[M];
struct zd{
	bool p;
	int pp;
}b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{	
		int l=0;
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]].p)
			{
				t[++l]=a[j];
				b[a[j]].p=true;
				b[a[j]].pp=l;
			}
			else
			{
				for(int k=b[a[j]].pp+1;k<=l;k++)
				{
					b[t[k]].p=false;
					t[k]=0;
				}
				l=b[a[j]].pp;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j].p)c[j]++;
			b[j].p=false;
			b[j].pp=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
