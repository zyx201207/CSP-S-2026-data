#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	
	int m,n;
	scanf("%d%d",m,n);
	for(int i=0;i<m;i++)
	{
		scanf("%c",a[i]);
	}
	sort(a+1,a+m+1);
	printf("%c",a[m/2+1]);
	
	return 0;
}
