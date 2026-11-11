#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	cin>>n;
	string s="",t;
	while(n--){
		long long a;
		char c;
		scanf("%lld%c",&a,&c);
		t=string(a,c);
		s+=t;
	}
	for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-1-i])l++;
	cout<<l;
	return 0;
} 
