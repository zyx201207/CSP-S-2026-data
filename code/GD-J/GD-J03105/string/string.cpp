#include<bits/stdc++.h>
using namespace std;
int n,num,turn,a;
string all,all_r;
char c1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %c",&num,&c1);
		a+=num;
		for(int j=0;j<num;j++)
		{
			all+=c1;
		}		
	}
	all_r=all;
	reverse(all_r.begin(),all_r.end());	
	for(int i=0;i<a;i++)
	{
		if(all[i]!=all_r[i])
		{
			turn++;
		}
	}
	turn/=2;
	printf("%d",turn);
	return 0;
}
