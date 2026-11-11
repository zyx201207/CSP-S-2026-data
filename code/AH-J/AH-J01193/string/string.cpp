#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,a[200011];
char s[200011];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	   cin>>a[i]>>s[i];
    if(n==1)cout<<0;
    if(n==2){if(s[1]==s[2])cout<<0;
		else if(a[1]<a[2])cout<<a[1];
    else cout<<a[2];}
    return 0;
}
