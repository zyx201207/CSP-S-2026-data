#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[2005],b=0,sum=0;
	char c[100005],ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch;
		b+=a[i];
		for(int j=b-a[i];j<=b;j++){
			c[j]=ch;
		}
	}
	for(int i=0;i<n;i++){
		if(c[i]!=c[n-i]){
			sum++;
		}
	}
	sum/=2;
	cout<<sum;
	return 0;
}
