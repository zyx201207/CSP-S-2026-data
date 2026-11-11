#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w".stdout);
	int n,m;
	cin>>n>>m;
	int a[200000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[m+2]={};
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i]<a[j]){
				if(a[j]!=b[i-1]){
					b[i]=a[j];
				}
			}
		}
	}
	cout<<b[m];
	return 0;
}
