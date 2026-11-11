#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char s[10000];
	cin>>s;
	if(n==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
		}
		if(s[1]!=s[2])
		cout<<1;
		else
		cout<<0;
	}
	if(n==1)
	cout<<0;
}
