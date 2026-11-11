#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,m=0;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long i=0;i<a;i++){
			s+=c;
		}
	}
	long long t=s.length();
	if(t%2==0){
		for(long long i=0;i<t/2;i++){
			if(s[i]!=s[t-i-1]){
				m++;
			}
		}
	}
	else{
		for(long long i=0;i<(t-1)/2;i++){
			if(s[1]!=s[t-1-i]){
				m++;
			}
		}
	}
	cout<<m;
}
