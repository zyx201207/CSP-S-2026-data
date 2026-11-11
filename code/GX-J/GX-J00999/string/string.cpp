#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int t;
string s="";
long long ans;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
	  int x;
	  scanf("%d",&x);
	  char c;
	  cin>>c;
	  while(x--)
	    s+=c;
	}
	int len=s.size();
	for(int i=0;i<len;i++)
	  if(s[i]!=s[len-i-1])
	    ans++;
	 cout<<ans/2;
    return 0;
}
