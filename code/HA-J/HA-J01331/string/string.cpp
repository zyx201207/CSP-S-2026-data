#include  <bits/stdc++.h>
using namespace  std;
string s1,s2;
int main( ){
	freopen (string.in,"r",stdin);
	freopen (string.out,"w",stdout);
int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s2=s2+y;
		}
	}
	long long k=0;
	for(int i=0;i<s2.size();i++){
		if(s2[i]!=s2[s2.size()-1-i]){
			k++;
		}
	}
	cout<<k/2;
	return 0;
}
