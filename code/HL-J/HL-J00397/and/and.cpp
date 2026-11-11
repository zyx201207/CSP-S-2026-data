#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long mx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(int(sqrt(n)*sqrt(n))==n){
		int sum=0;
		for(int i=1;i<=m;i=i*2){
			sum=sum+i;
		}
		cout<<a[n]-sum/2;
	}else{
		cout<<mx;	
	}
	return 0;
}
