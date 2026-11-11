#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,g=0;
	string s,f;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char d;		
		cin>>a>>d;
		for(long long j=1;j<=a;j++){
			s=s+d;
			f=d+f;
		}
	}
	for(long long i=0;i<=s.size();i++){
		if(s[i]!=f[i]){
			g++;
		}
	}
	g/=2;
	cout<<g;
	return 0;
}