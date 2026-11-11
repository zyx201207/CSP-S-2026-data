#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
long long d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--)
		if(s[i]!=s[j])
			d++;
	cout<<d;
	return 0;
} 
