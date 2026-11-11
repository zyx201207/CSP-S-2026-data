#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005],s[200005];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,b=0,z;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		z=l;
		l+=a[i];
		for(long long j=z;j<=l;j++){
			s[j]=c[i];
		}
	}
	for(long long i=1;i<=l;i++){
		if(s[i]!=s[l+1-i]){
			b++;
			s[l+1-i]=s[i];
		}
	}
	cout<<b;
	return 0;
}
