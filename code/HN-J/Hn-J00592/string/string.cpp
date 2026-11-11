#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,x[20001],s=0,n=0;string h[1000001];char y[200001],d;bool k=1;
	cin>>t;
	cin>>x[1]>>y[1];
	d=y[1];
	for(int i=2;i<=t;i++){
		cin>>x[i]>>y[i];
		if(d!=y[i])k=0;
		s+=x[i];
		for(int j=1;j<=x[i];j++)h[j]=y[i];
	}
	if(k){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=s;i++){
		if(h[i]!=h[s-i+1])n++;
	}
	cout<<n;
 return 0;
}
