#include<bits/stdc++.h>
using namespace std;
int n,a,sum;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++)
			s=s+b;
	}
	n=s.size();
	for(int i=0;i<n/2;i++)
		if(s[i]!=s[n-i-1]) sum++;
	cout<<sum;
	return 0;
}
