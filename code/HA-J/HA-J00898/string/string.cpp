#include<bits/stdc++.h>
using namespace std;
long long n,a,k;
string s;
char t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		k+=a;
		cin>>t;
		for(int j=1;j<=a;j++)
		{
			s+=t;
		}
	}
//	while()
//	{
//		
//	}
	cout<<k/2;
	return 0;
}
