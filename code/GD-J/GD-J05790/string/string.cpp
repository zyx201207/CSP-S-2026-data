#include<bits/stdc++.h>
using namespace std;
int n=0;
int m[200005];
char c[200005];
long long b[27];
long long z=-1;
long long max;
int v=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long max;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	max=m[1];
	for(int i=2;i<=n;i++){
		max=max+m[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i-1]){
			v=0;
		}
	}
	if(v==1){
		cout<<0;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			b[int(c[i])-96]=b[int(c[i])-96]+m[i];
		}
		for(int i=1;i<=26;i++){
			if(b[i]>z){
				z=b[i];
			}
		}
		long long d=max-z;
		if(n%2!=0){
			cout<<d-1;
		}else{
			cout<<d;
		}
	}
	return 0;
}
