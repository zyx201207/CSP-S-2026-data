#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,f=1,cnt=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;char c;
		cin>>x>>c;
		for(long long i=1;i<=x;i++){
			s+=c;
		}
	}
	long long i;
	for(i=0;i<(1l*(long long)s.size());i++){
		if(s[i]!=s[s.size()-i-1]){
			f=0;
			cnt++;
		}
	}
	if(f==1){
		cout<<0;
	}else{
		cout<<cnt/2;
	}
	return 0;
}
