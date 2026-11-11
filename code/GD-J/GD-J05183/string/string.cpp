#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	string s;
	struct c{
		int a;
		char u;
	}c[n+1];
	for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].u;
		for(int j=1;j<=c[i].a;j++){
			s=s+c[i].u;
		} 
	}
	
	long long len=s.size();
	long long cnt=0;
	
	for(int i=0;i<=len/2-1;i++){
		if (s[i]!=s[len+1-i]){
			cnt++;
		}
		
	}
	cout<<cnt;
	return 0;
}
