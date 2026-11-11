#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],cd,bj[500010];
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
		int b[m+10];
		cd=0;
		for(int j=1;j<=m+10;j++) b[j]=0;
		for(int j=1;j<=n;j++) s[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				cd++;
				b[a[j]]=cd;
				s[cd]=a[j];
			}
			else
			{
				for(int k=b[a[j]]+1;k<=cd;k++) b[s[k]]=0,s[k]=0;
				cd=b[a[j]];
			}
		}
		for(int j=1;j<=cd;j++)
		{
			bj[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<bj[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
