#include <bits/stdc++.h>
using namespace std;
char a[900000005],b[900000005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long q=0;
	
	long long n,in,num=1;
	char m;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>in>>m;
		for(long long j=num;j<=num+in;j++){
			a[j]=m;
			b[j]=a[j];
			
		}
		num+=in;
	}
	for(long long i=1;i<=num/2;i++){
		a[num-i]=a[i];
	}
	for(long long i=1;i<=num;i++){
		if(a[i]!=b[i]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
