#include<bits/stdc++.h>
using namespace std;
char a[100000005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0;;
	for(long long  i=1;i<=n;i++){
		char s;
		long long  k;
		cin>>k>>s;
		for(long long  j=1;j<=k;j++){
			a[ans]=s;
			ans++;
		} 
	} 
	long long sum=0;
	for(long long  i=0;i<ans/2;i++){
		if(a[i]!=a[ans-i-1]){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
