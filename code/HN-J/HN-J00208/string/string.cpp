#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	string s="",c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	int u,z=s.size();
	u=z/2;
	int oo=0;
	for(int i=0;i<u;i++){
		if(s[i]!=s[z-i-1])oo++;
	} 
	cout<<oo;
}
