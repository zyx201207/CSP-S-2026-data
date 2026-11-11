#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long s;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	char b[2000005];
	long long d=1;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=a[i]; j++){
			b[d]=c[i];
			d+=1;
		}
	}
	d-=1;
	for (int i=1; i<=d/2; i++){
		if (b[i]!=b[d-i+1]){
			s+=1;
		}
	}
	cout<<s;
	
	return 0;
}
