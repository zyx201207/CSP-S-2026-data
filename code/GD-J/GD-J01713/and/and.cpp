#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,max=0,max1=0,s[10000],o;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>s[i];
	}
	sort(s,s+a+1);
	for(int i=a;i>=a-b+2;i--)
	{
		s[i+1]=(s[i]&s[i+1]);
	}
	cout<<s[a-b+1];
}
