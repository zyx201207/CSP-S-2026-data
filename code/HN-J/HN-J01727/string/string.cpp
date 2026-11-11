#include<bits/stdc++.h>
using namespace std;
long long n,t,tot;
int a[1000000];
char b[1000000],c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++) c[j+t]=b[i];
		t+=a[i];
	}
	for(int i=1;i<=t/2;i++){
		if(c[i]!=c[t-i+1]){
			 c[t-i+1]=c[i];
			 tot++;
		}
	}
	cout<<tot;
}
