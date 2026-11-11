#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	string a[1000000000];
	long long sizee=0;
	for(long long i=0;i<n;i++){
		long long b;
		char c;
		cin>>b>>c;
		for(long long i=sizee;i<b+sizee;i++){
			a[i]=c;
		}
		sizee+=b;
	}
	string b[sizee];
	for(long long i=0;i<sizee;i++){
		b[i]=a[i];
	}
	long long sum=0;
	for(long long i=sizee-1;i>=0;i--){
		if(a[i]==b[sizee-i-1])
			++sum;
	}
	if(sum==sizee){
		cout<<0;
		return 0;
	}
	return 0;
} 
