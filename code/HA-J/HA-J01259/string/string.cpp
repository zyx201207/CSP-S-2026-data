#include <bits/stdc++.h>
using namespace std;
string y,c;
char z;
int n;
long long a[200010],k=0,s=0,x[200000000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			z=c[i];
			x[k+j]=z;
		}
		k+=a[i];
	}
	for(long long i=1,j=k;i!=j;i++,j--){
		if(x[i]!=x[j]){
			s++;
			
		}
	}
	cout<<s;
	return 0;
}
