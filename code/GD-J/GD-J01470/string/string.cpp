#include<bits/stdc++.h>
using namespace std;
long long n,a,s;
string b;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)b+=c;
	}
	for(int i=0;i<b.size()/2;i++){
		if(b[i]!=b[b.size()-i-1])s++;
	}
	cout<<s;
}
