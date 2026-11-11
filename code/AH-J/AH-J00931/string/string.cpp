#include<bits/stdc++.h>
using namespace std;
long long b[267911];
char a[256733];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0,s2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		s2+=b[i];
		for(long long j=1;j<=b[i];j++){
			s+=a[i];
			s1+=a[i];
		}
	}
	long long p=s.length();
//	cout<<p;
	reverse(s1.begin(),s1.end());
	if(s1==s) cout<<0;
	else{
		for(long long i=0;i<p/2;i++){
			if(s[i]!=s1[i]) t++;
		}
	}
	cout<<t;
}
