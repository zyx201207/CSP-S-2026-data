#include<bits/stdc++.h>
using namespace std;
struct sss{
	long long a=0;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	sss x[n+5];
	string s;
	long long i;
	long long j;
	long long l=0;
	for(i=0;i<n;i++){
		cin>>x[i].a>>x[i].c;
		for(j=0;j<x[i].a;j++){
			s+=x[i].c;
			l++;
		}
	}
	long long r=0;
	for(i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			r++;
		}
	}
	cout<<r;
	return 0;
}
