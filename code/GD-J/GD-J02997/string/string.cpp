#include<bits/stdc++.h>
using namespace std;
/*
string and(string a,string b){
	
	string ans;
}
*/
long long ans,n,Sum;
long long a[200005];
string s,b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n); 
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s=s+b[i];
		}
	}
	int L=0,R=s.size()-1;
	while(L<R){
		if(s[L]!=s[R]) Sum++;
		L++;
		R--;
	}
	cout<<Sum;
	return 0;
}
