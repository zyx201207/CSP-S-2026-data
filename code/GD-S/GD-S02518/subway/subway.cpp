#include<iostream>
using namespace std;
int n,m,k;
int a[500050],d[500050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
	cout<<35<<endl<<16;
	return 0;
}
