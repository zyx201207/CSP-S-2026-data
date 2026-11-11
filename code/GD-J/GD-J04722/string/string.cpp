#include <bits/stdc++.h>
using namespace std;
long long n,a,len,cnt;
char c;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}
	
	len=s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]){
			s[len-i-1]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 

