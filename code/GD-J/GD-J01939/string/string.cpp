#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	long long sum=0;
	string p[100000001];
	for(int i=0;i<a;i++){
		long long m,n;
		cin>>m;
		cin>>n;
		for(int i=sum;i<m+sum;i++){
			p[i]=n;
		}
		sum+=m;
	}
	long long arr=0;
	for(int i=0;i<sum%2;i++){
		if(p[i]!=p[sum-i-1]){
			arr++;
		}
	}
	cout<<arr;
	return 0;
} 
