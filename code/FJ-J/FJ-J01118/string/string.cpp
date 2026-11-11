#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum=0;
	char c;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<=(s.length()-1)/2;i++){
		if(s[i]!=s[s.length()-1-i]){
			s[s.length()-1-i]=s[i];
			sum++;
		}
	}
	cout<<sum;
}
