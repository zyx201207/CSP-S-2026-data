#include<bits/stdc++.h>
using namespace std;
int n;
long long m[100005];
string o;
string s[1000005];
long long sum;
long long  k;

int main()
{   
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
scanf("%d",&m[i]);
	cin>>o;
	sum+=m[i];
	for(int j=sum-m[i]+1;j<=sum;j++)
	{
		s[j]=o;
		
	}
	
}
for(int i=1;i<=sum/2;i++)
{
	
	if(s[i]!=s[sum-i+1])k++;
	
}

printf("%d",k);

fclose(stdin);
fclose(stdout);
	return 0;
}
