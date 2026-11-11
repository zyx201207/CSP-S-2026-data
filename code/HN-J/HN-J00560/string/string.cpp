#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m=0;
string s[200005],d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >>a[i]>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			d+=s[i];
	for(int i=0,i<=s.length();i++)
		if(s[i]=s[s.length()+1-i])
			continue;
		else
			break;
		cout<<0;
	return 0;
}
