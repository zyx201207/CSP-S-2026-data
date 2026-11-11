#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long m=0,o=1,cn=0,l[200010];
char c[200010];
int aa(long long x){
	for(int i=1;i<=n;i++){
		if(x<=l[i])return i;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		l[i]=l[i-1]+a[i];
	}
	int ap,bp,z;
	while(o<=m/2){
		ap=aa(o);bp=aa(m+1-o);
		z=min(a[ap],a[bp]);
		if(a[ap]<a[bp]){
			a[bp]-=z;
		}
		else {
			a[ap]-=z;
		}
		if(c[ap]!=c[bp]){
			cn+=z;
		}
		o+=z;
	}
	cout<<cn;
	return 0;
}
