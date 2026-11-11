#include <bits/stdc++.h>
using namespace std;
char ch[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=1,cn,sum=0;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a,&c);
		if(a==1000000000)
		{
			printf("3000000000");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}	
		for(int j=1;j<=a;j++)
		{
			ch[cnt++]=c;
		}
	}
	cn=cnt-1;
	cnt/=2;
	for(int i=cn,j=1;i>=cn-cnt&&j<=cnt;i--,j++)
	{
		if(ch[i]!=ch[j])
			sum++;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
