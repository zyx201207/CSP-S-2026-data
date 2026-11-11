#include<bits/stdc++.h>
using namespace std;
long long t,n,sum,num,k[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>sum;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	num=k[n-1];
//	cout<<num<<endl;
	for(long long i=1;i<sum;i++){
		num=(num&k[n-i-1]);
//		cout<<k[n-i-1]<<endl;
	}
	cout<<num;
}
