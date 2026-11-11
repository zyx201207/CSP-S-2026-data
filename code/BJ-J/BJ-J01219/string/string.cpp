#include<bits/stdc++.h>
using namespace std;
long long n,a[200020];
char c[200020];
string s=".";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long sum=0;
	for(long long i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]) sum++;
	}
	cout<<sum;
	return 0;
}
