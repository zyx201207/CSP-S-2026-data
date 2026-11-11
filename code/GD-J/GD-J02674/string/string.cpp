#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[1000005],sum=0;
	string s;
	cin >>n;
	char c[1000005];
	for(long long i=1;i<=n;i++){
		cin >>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	long long b=s.length()-1;
	for(long long i=0;i<s.length()/2;i++){
		if(s[i]!=s[b]){
			sum++;
		}
		b--;
	}
	cout<<sum;
	return 0;
}
