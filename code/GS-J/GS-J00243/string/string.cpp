#include<bits/stdc++.h>
using namespace std;
long long a[300010],p=0,o;
long long m=0;
string b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=0;i<n;i++){
		c+=a[i]*b[i];
		p+=a[i];
	}
	o=p;
	p/=2;
	for(long long i=0;i<p;i++){
		if(c[i]!=c[o-i-1]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
