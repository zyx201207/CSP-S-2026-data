#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],n,m,w[N],s[M];
bool v[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		w[i]=s[a[i]];
		s[a[i]]=i;
	}	
	int l=1;
	memset(s,0,sizeof(s));
	while(l<=n)
	{
		memset(v,false,sizeof(v));
		for(int i=l;i<=n;i++)
			if(!v[w[i]]&&w[i]>=l) 
			{
				for(int j=w[i];j<i;j++)
					v[j]=true;
			}	
		for(int i=l;i<=n;i++)
			if(!v[i])
				s[a[i]]++;
		l++;	
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<' ';
	return 0;
}
