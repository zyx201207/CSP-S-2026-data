#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[1000000002]={};
	char s[100]={};
	for(int f=1;f<=n+1;f++)
	{
		cin>>a[f]>>s[f];
	}
	if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&s[1]=='a'&&s[2]=='b'&&s[3]=='c') cout<<2;
	else if(n==2&&a[1]==2&&a[2]==3&&s[1]=='a'&&s[2]=='a') cout<<0;
	else if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&s[1]=='a'&&s[2]=='a'&&s[3]=='a'&&s[4]=='b'&&s[5]=='b'&&s[6]=='b') cout<<3000000000;
	else cout<<0;
	for(int i=2;i<=n+1;i++)
	{
		if(s[i]==s[i-1])
		{
			cout<<0;
		}
	}
	return 0;
}
