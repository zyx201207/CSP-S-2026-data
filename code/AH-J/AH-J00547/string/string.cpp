#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
const long long M=1e9;
long long n;
long long a[N+5];
char b[N+5];
char c[M+5];
long long mun=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	int i=0,k=0;
	while(k<n){
		for(int j=0; j<k ; j++){
			c[i]=b[k];
			i++;
		}
		k++;
	}
	for(int j=0; j<(i/2); j++)
		if(c[j]==c[i-1-j])	mun++;
	cout<<mun;
	return 0;
}
