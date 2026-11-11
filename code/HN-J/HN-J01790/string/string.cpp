#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
long long n,a[N],i1=1,j11,cat,mi;
char c[N];
string b;

int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	j11=n;
	while(i1<j11){
		if(c[j11]!=c[i1]){
			cat+=min(a[j11],a[i1]);
		}
		mi=min(a[j11],a[i1]);
		a[j11]-=mi;
		a[i1]-=mi;
		if(a[i1]<=0){
			i1++;
		}
		if(a[j11]<=0){
			j11--;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' '<<c[i]<<'\n';
//	}
	cout<<cat;
	return 0;
} 
