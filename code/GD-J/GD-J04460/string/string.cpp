#include<bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int z=0;
	long long z1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		z1=z1+a[i];
		if(c[i]==c[i-1]){
			z+=1;
		}
	}
	if(z==n){
		cout<<0;
	}
	if(z==n-2){
		cout<<z1/2;
	}
	return 0;
}
