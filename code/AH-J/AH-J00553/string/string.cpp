#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string str;
	int n;
	cin>>n;
	int cnt=0;
	int len=0;
	for(int k=1;k<=n;k++)
	{
		int t;
		cin>>t;
		len+=t;
		char q;
		cin>>q;
		for(int j=1;j<=t;j++)
		{
			str+=q;
		}
	}
	for(int i=0;i<=len/2;i++)
	{
		if(str[i]!=str[len-i-1])
		{
			cnt++;
			str[len-i-1]=str[i];
		}
	}
	cout<<cnt;
	return 0;
}
