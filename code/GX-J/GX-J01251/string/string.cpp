#include<bits/stdc++.h>
using namespace std;
int n;
string s={0};
int main()
{
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s[j]=b;
		}
	}
	cout<<s;
	return 0;
}
