#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s="",a="",b="",c="",d="";
	for(int i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b; 
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	for(int i=0;i<s.size();i++){
		a+=s[i];
	}
	for(int i=s.size()-1;i>=0;i--){
		b+=s[i];
	}
	if(a==b){
		cout<<0;
		return 0;
	}
	int t=s.size();
	for(int i=0;i<t;i++){
		if(a[i]!=a[t-i-1]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}


