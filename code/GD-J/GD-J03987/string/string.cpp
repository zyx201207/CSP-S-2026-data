#include<bits/stdc++.h>
using namespace std;
long long n,sum1;
struct l{
	long long m;
	char s;
};
l a[10000000];
string b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i].m>>a[i].s;
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i].m;j++){
			b+=a[i].s;
		}
	}
	for(long long i=n-1;i>=0;i--){
		for(long long j=0;j<a[i].m;j++){
			c+=a[i].s;
		}
	}
	long long e=b.size();
	for(long long i=0;i<e;i++){
		if(b[i]==c[i]){
			sum1++;
		}
	}
	cout<<(e-sum1)/2;
	return 0;
}
