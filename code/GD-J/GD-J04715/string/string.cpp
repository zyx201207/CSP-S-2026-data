#include<bits/stdc++.h>
using namespace std;
string c[2000000001],f[2000000001];
long long n,a[10001],s=0,d=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld %c",&a[i],c[i]);
		for(int j=s;j<s+a[i];j++){
			f[j]=c[i];
		}
		s+=a[i];
	}
	for(int i=0;i<s/2;i++){
		if(f[i]!=f[s-i-1]){
			d++;
		}
	}
	printf("%lld",d);
	return 0;
} 
