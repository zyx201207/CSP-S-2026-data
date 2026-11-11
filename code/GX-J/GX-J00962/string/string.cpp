#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int n,a[200010],ans;
char ch;
string s,ls,rs;
int main()
{
		freopen("string1.in","r",stdin);
		freopen("string.out","w",stdout);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
	    {
				cin>>a[i]>>ch;
				for(int j=1;j<=a[i];j++) s+=ch;
		}
		int len=(int)s.size(),l=(len+1)/2,r=l;
		for(int i=l-1;i<=r-1;i++) ls+=s[i];
		for(int i=len-1;i>=r;i--) rs+=s[i];
		for(int i=0;i<=l-1;i++)
			if(ls[i]!=rs[i]) ans++;
		printf("%d",ans);
		return 0;
}

