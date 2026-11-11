#include<iostream>
using namespace std;
long long n,m,k;
long long a[500050],d[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int j=a[i]-a[i-1];
		int p=i-1;
		d[i]=j*p+k;
		k+=d[i];
	}
	for(int i=n;i>=1;i--){
		if(d[i]==m){
			cout<<i;
			break;
		}
	}
	return 0;
}
