#include<bits/stdc++.h>
using namespace std;
long long c[200000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,aum=0;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			c[sum]=b[i]-'a';
			sum++;
		}
	}
	sum-=1;
	for(int i=0;i<sum/2;i++){
		if(c[i]!=c[sum-i]){
			 aum++;
		}
	}
	cout<<aum;
	return 0;
}
