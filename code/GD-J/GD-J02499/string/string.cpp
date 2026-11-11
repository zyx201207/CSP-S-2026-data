#include<bits/stdc++.h>
using namespace std;
long long n,a,l,sum;
string s;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		l+=a;
		while(a--){s+=b;}
	}
	for(int i=0;i<l/2;i++)if(s[i]!=s[l-i-1])sum++;
	cout<<sum;
	return 0;
} 
