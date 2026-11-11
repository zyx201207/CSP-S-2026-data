#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;cin>>n;
	int o=1;
	long long a[n+1],l=0;
	char b[n+1]; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		o+=a[i];
	}
	char op[o];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
		op[j+l]=b[i];
		l+=a[i];
	}
	for(int i=1;i<=o/2;i++){
		if(op[i]!=op[o-i])
		k++;
	}
	cout<<k;
}
