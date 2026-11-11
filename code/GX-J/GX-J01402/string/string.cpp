#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
string x1,s;
long long n,x,num=0;
int main()
 {
	  freopen("string.in","r",stdin);
	  freopen("string.out","w",stdout);
	  cin>>n;
	  for(int i=1;i<=n;i++)
	  {  cin>>x;for(int j=1;j<=x;j++)cin>>x1;s+=x1;}
	  long long len=s.size();
	  for(int i=len/2+1,j=len/2+1;i<=len;i++,j--){if(s[i]!=s[j])num++;}
		cout<<num;
       return 0;
 }
 
