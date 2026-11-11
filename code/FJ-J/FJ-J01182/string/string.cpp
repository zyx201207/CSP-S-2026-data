#include<bits/stdc++.h>
using namespace std;
int a[1111100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s,c;
	cin>>s>>c;
	for(int i=0; i<=n-1; i++)
	{
		cin>>a[i];
	     if(s[i]>='a'&&s[i]<='z')
	     {
	          c=a[s[i]-'0']++;
		 }
	}
	int cnt=0;
	int len=s.size();
	for(int i=0; i<=(len-1)/2; i++)
	{
		if(a[i]==len-1-i)
		{
		    break;
		}
		else
		{
		       c=len-m;
		       cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
