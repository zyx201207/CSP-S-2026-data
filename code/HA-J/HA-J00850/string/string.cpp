#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
    long long a[n];
    char c[n];
	string big;
	long long sum=0;
	long long l=0;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
		cin>>c[i];
		l+=a[i];
		string k;
		k[0]=c[i];
		for(int j=0;j<=a[i]-1;j++){
			big+=k[0];
		}
	}
	for(int i=0;i<=l/2-1;i++){
		if(big[i]!=big[l-1-i]){
			sum+=1;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
