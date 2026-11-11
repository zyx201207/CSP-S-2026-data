#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	long long num=0;
	long long a[n]={};
	long long c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c=a[i];
		
		for(int j=1;j<=m;j++){
			c=c and a[i+j];
		}
		if(c>num){
			num=c;
		}
	}
	cout<<num;
	return 0;
}
