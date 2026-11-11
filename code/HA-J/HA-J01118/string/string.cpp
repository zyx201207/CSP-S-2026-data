#include <bits/stdc++.h>
using namespace std;
int c[10000100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char b;
	int n,a,d=1,k;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			c[d]=b;
			d++;
		}
	}
	int sum=0;
	for(int i=1;i<=d/2;i++){
		if(c[i]!=c[d-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
