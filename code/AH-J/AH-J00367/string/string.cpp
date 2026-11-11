#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N=2*1e5+10;
int n;
long long a[N];
char c[N];
string s;

bool is_palindrome(string str)
{
	string assist=str;
	
	reverse(str.begin(),str.end());
	
	if(assist==str)return 1;
	return 0;
}

int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  
  s="";
  
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
  
  long long len=0;
  for(int i=1;i<=n;i++)len+=a[i];
  
  int currentstandard=a[1],cnt=1;
  for(int i=0;i<len;i++)
  {
	  if(i==currentstandard)currentstandard+=a[++cnt];
	  s+=c[cnt];
  }
  
  if(is_palindrome(s))return cout<<0,0;
  
  string s1="",s2="";
  
  int divide=0;
  if(len%2==0)
  {
	  divide=len/2;
	  
	  for(int i=0;i<divide;i++)s1+=s[i];
	  for(int i=divide;i<len;i++)s2+=s[i];
  }
  else 
  {
	  divide=(len-1)/2;
	  
	  for(int i=0;i<divide;i++)s1+=s[i];
	  for(int i=divide+1;i<len;i++)s2+=s[i];
  }
  
  long long ans=0,comp=s1.size();
  for(int i=0;i<comp;i++)
	  if(s1[i]!=s2[i])ans++;
  
  cout<<ans;
  
  return 0;
}
