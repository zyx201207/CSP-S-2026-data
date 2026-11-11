#include<bits/stdc++.h>
#define t long long
#define ll unsigned long long
using namespace std;
t n,a[200005],sum,sum1;
char c[200005];
string s;
int main(int argc,char** argv)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(t i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(t j=1;j<=a[i];j++)s+=c[i];
	}
	for(t i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])sum++;
	}
	cout<<sum;
}
//o(n)
