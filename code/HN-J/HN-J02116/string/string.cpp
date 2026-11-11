#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,s=0,d=0,x=0;
	char c,o[1000000000];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<=a;j++){
			o[j]=c;
			d=d+1;
		}
	}
	for(long long i=d;i>=1000000000/2;i--){
		if(o[s]!=o[i]){
			x++;
		}
		s++;
	}
	cout<<x;
	return 0;
} 
