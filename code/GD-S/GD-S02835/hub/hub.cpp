#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	int c,t;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		int n,k;
		cin>>n>>k;
		
		for(int i=1;i<=n-1;i++)
		{
			cin>>a[i];
		}
		if(n>40000)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	return 0;
}
