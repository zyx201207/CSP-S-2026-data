#include<stdio.h>
#include<iostream>
using namespace std;
long long n,ans;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a1;
		string s1;
		cin>>a1>>s1;
		for(int i=1;i<=a1;i++){
			s=s+s1;
		}
	}
	for(long long i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
