#include<bits/stdc++.h>
using namespace std;
long long n,sum,a[200005];
char b[200005];
string s,x,y;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
			s+=b[i];
	}
	for(int i=0;i<s.size()/2;i++)x+=s[i];
	if(s.size()%2==0)
		for(int i=s.size()/2;i<s.size();i++)y+=s[i];
	else 
		for(int i=s.size()/2+1;i<s.size();i++)y+=s[i];
	for(int i=0,j=y.size()-1;i<x.size(),j>=0;i++,j--)
		if(x[i]!=y[j])sum++;	
	cout<<sum;
	return 0;
}
