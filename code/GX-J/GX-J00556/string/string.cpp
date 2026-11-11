#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,a=0,len=0,cs=0;
	string w,c,c2;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>w;
		for(long long j=1;j<=a;j++){
			c+=w;
		}
		len+=a;
	}
	for(long long i=len;i>=1;i--){
		c2+=c[i];
	}
	for(long long i=1;i<=len;i++){
		if(c2[i]!=c[i]) cs+=1;
	}
	cout<<cs;
	return 0;
}
