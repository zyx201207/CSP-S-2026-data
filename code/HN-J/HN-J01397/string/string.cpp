#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a,o=0,l=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		o=o+a;
		for(int j=1;j<=a;j++){
			s=s+c;
		}
	}
	for(int i=1;i<=o/2;i++){
		for(int j=o;j>=o/2;j--){
			if(s[i]!=s[j]) l++; 
		}
	}
	cout<<l/3;
	return 0;
}
