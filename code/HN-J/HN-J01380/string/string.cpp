#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	cout<<sum/2;
}
