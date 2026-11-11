#include<bits/stdc++.h>
using namespace std;
int g[20100];
char z[20100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,mid=0,sum=0;
	string s={};
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>g[i]>>z[i];
	}
	for(int i=1;i<=n;i++){
		mid+=g[i];
	}
	long long midd=mid;
	mid=(mid+1)/2;
	long long ss=0,mmid,d;//mmid  第几位的   第几个 
	for(int i=1;i<=n;i++){
		ss+=g[i];
		if(ss>mid){
			mmid=mid-ss+g[i];
			d=i-1;
			break;
		}
	}
	long long j=d;
	for(long long i=d;i<=n;i++){
		if(z[i]!=z[j]){
			sum+=g[i];
		}
		j--;
	}
	cout<<sum;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
