#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="",s1="",s2="";
	while(n--){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int i=0;i<a;i++){
			s=s+c;
		}
	}
	int b=s.size()/2;
	int ans=0;
	int j=b+1;
	for(int i=b;i>0;i--){
		char c=s[i];
		if(s[j]!=c) ans++;
	}
	cout<<ans+1;
	return 0;
}
