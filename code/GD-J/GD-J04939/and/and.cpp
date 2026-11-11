#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=INT_MIN,maxn1;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//±ðÍü¼Ç½Ó´¥×¢ÊÍ£¡£¡£¡£¡£¡ 
	cin>>n>>m;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];	
	} 
	for(int i =1;i<=n;i++)
	{
		if(m==1)
		{	
			maxn = max(maxn,a[i]);
		}	
	} 
	cout<<maxn;
	return 0;
}


