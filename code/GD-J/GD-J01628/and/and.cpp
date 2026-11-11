#include<bits/stdc++.h>
using namespace std;
int cmp(int x1,int y1)
{
	return x1>y1;
}
int main()
{freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[100005];
	for(int i=1;i<=n;i++)
	{
	
		cin>>a[i];
	
	}
	sort(a+1,a+1+n,cmp);
	string aa[m+1];
	int maxn=-1e9;
//	cout<<1;
	for(int i=1;i<=m;i++)
	{
		string s;
		int x=a[i],k=0;
		while(x>=1)
		{
			if(x%2==1)s[k]='1';
			else s[k]='0';
			x/=2;
			k++;
		} 
		s[k]=x;
		maxn=max(k,maxn);
		int jj=0;
		for(int j=k;j>=0;j--)
		{
			aa[i][j]=s[jj];
			jj++;
		}
	}
	string ans;
		for(int j=0;j<maxn;j++)
		{
			ans[j]=aa[1][j];
		}
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			if(ans[j]=='1'&&aa[i][j]=='1')ans[j]='1';
			else ans[j]='0';
		}
		//cout<<1;
		
	}
	long long aans=0,sas=1;;
		for(int j=maxn;j>=0;j--)
		{
//	cout<<ans[j];
			if(ans[j]=='1')aans+=sas;
			sas*=2;
		}	
		cout<<aans;
}
