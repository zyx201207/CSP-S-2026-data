#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
const int N=1e5+5;
long long x[N],num[N];
int main(){
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		long long m=n-d;
		if(m==0)num[i]=0;
		if(m%2!=0)num[i]=(m+1)/2;
	}
	for(int i=1;i<=t;i++){
		cout<<num[i];
	}
	return 0;
}