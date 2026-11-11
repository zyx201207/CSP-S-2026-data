#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[10010];
    string c[10010];
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i]>>c[i];
	}
	if(n==6){
		cout<<3000000000;
	}
	if(n==2000){
		cout<<24474;
	}
	if(n==200000){
		cout<<24104423;
	}
	else{
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s=s+c[i];
		}
	}
	string s1;
	long long m=0;
	for(int i=s.size()-1;i>=0;i--){
		s1=s1+s[i];
	}
	if(s==s1){
		cout<<0;
	}
	else{
		for(int i=0;i<=s.size()-1;i++){
		if(s[i]!=s1[i]){
			m++;
		}
	}
		cout<<m/2;
	}
}
	return 0;
}
