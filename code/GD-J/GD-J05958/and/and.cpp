#include<iostream>
using namespace std;
int a[10005],b[10005];
int mx=0;
freopen("and.in","r",stdin)
freopen("and.out","w",stdout)
int main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]&a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(b[i]|b[i-m+1]>mx){
			mx=b[i];
		}
	}
	cout<<mx;
	return 0;
}
