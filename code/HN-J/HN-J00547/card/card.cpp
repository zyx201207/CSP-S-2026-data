#include<bits/stdc++.h> 
using namespace std;
int a[200005];
bool b[200005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	
	int n,m,x=1;
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==1)
	{
		cout<<n;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
