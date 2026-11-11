#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		string a;
		int b;
		cin>>b>>a;
		for(long long j=1;j<=b;j++){
			s+=a;
		}
	}
	long long sum=0;
	for(long long i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-1-i])sum++;
	}
	cout<<sum;
}
