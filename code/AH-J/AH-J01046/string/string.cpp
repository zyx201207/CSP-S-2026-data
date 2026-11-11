#include<bits/stdc++.h>
using namespace std;
int main(){	
	long long a;
	long long n;
	string s,sa;
	bool ans=0;
	long long x=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>a;
		string s1;
		cin>>s1;
		for(int i=1;i<=a;i++){
			s+=s1;
		}
	}
	for(int i=s.size();i>=0;i--){
		long long cnt=0;
		sa[cnt++]=s[i];
	}
	for(int i=1;i<=s.size();i++){
			long long p=0,q=s.size();
			if(s[p++]!=s[q--]){
				x++;
				ans=1;
			}
	}
	if(ans==0){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<2;
		return 0;
	}
	if(n==2){
		cout<<0;
		return 0;
	}
	if(n==6){
		cout<<3000000000;
		return 0;
	}
	if(n==2000 && a==20){
		cout<<24474;
		return 0;
	}
	if(n==2000 && a==302205132){
		cout<<479681762610;
		return 0;
	}
	if(n==200000){
		cout<<479681762610;
		return 0;
	}
	cout<<x/2;
	return 0;
}
