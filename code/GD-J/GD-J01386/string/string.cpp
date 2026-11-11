#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;	
		}
	}
	long long flag=0;
	for(long long i=s.size()-1;i>=s.size()/2;i--){	
		if(s[flag]!=s[i])sum++;
		flag++;
	}
	cout<<sum;
	return 0;
} 
