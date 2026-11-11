#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;++i){
		scanf("%lld %c",&a[i],&b[i]);
	}
	long long t=0;
	for(long long i=1,j=n;i<j;){
		if(b[i]!=b[j]){
			if(a[i]>=a[j]){
				a[i]-=a[j];
				t+=a[j];
				--j;
			}else{
				a[j]-=a[i];
				t+=a[i];
				++i;
			}
		}else{
			if(a[i]>=a[j]){
				a[i]-=a[j];
				--j;
			}else{
				a[j]-=a[i];
				++i;
			}
		}
	}
	cout<<t;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
