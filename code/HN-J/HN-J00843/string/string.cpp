#include<bits/stdc++.h>
using namespace std;
const int N=4000005;
long long n,t=0;
long long a[N];
char c[N],s[N],r[N],l[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long u=0;
	scanf("%ld",&n);
	for(int i=1; i<=n; i++){
		scanf("%ld",&a[i]);
		scanf("%s",&c[i]);
		for(int j=1; j<=a[i]; j++){
			char z=c[i];
			u++;
			s[u]=z;
		}
	}
	for(int i=1; i<=u/2; i++) r[i]=s[i];
	for(int i=0; i<=u/2; i++) l[i]=s[u-i];
	for(int i=1; i<=u/2; i++){
		if(r[i]!=l[i]) t++;
	}
	cout<<t<<endl;
	return 0;
} 
