#include<bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char c;
}a[200002];
int n,maxx=-1;
string s="";
long long ans=0;
long long check(string s){
	long long prob=0;
	for(int i=0;i<s.length()/2;i++)
	{
		if(s[i]==s[s.length()-i-1])continue;
		prob++;
	}
	return prob;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%c%c",&a[i].num,&a[i].c,&a[i].c);
		if(a[i].num>maxx)maxx=a[i].num;
	}
	if((long long)n*maxx<=20000000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].num;j++)
			{
				s+=a[i].c;
			}
		}
		printf("%lld",check(s));
		return 0;
	}
	
	return 0;
}
