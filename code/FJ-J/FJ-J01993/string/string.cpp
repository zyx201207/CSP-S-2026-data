#include<bits/stdc++.h>
using namespace std;
int n,t=0,a[200005];
char c[200005];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s=s+c[i];
		}
	}
	int m=s.size();
	for(int i=0;i<m/2;i++)
	{
		if(s[i]==s[m-i-1])
		continue;
		else t++;
	}
	cout<<t;
	return 0;
}