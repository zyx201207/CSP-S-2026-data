#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,z=0,x=0,j=0,cnt=0;
	char c[1000005],d;
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b;
		cin>>d;
		z+=b;
		for(;j<z;j++){
			c[j]=d;
		}
	}
	for(long long i=0;i<a;i++){
		if(c[i]!=c[a-i]){
			c[a-i]=c[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
