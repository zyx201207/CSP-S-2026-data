#include<bits/stdc++.h>
using namespace std;
long long ans,n,len;
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++)
			str=str+c; 
	}
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		ans+=(str[i]!=str[j]);
	}
	cout<<ans;
	return 0;
}
