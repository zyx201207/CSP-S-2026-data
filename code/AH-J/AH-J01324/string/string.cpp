#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	long long t=s.size();
	for(int i=1;i<=t/2;i++){
		if(s[i]!=s[t+1-i]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
