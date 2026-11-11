#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s[100005];
	char s1[100005];
	int t;
	cin>>t;
	string a;
	for(int i=1;i<=t;i++){
		cin>>s[i]>>s1[i];
	}
	int d=s[1];
	for(int i=2;i<=t;i++){
		d=gcd(d,s[i]);
	}
	for(int i=1;i<=t;i++){
		s[i]/=d;
		for(int j=1;j<=s[i];j++){
			a+=s1[i];
		}
	}
	long long e=0;
	long long k=a.size();
	for(long long i=0;i<k;i++){
		if(a[i]!=a[k-1-i]){
			e++;
		}
	}
	cout<<e/2*d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
