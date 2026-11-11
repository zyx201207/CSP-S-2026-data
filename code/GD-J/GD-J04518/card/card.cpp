#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	cin>>m;
	int a[5000000]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c[3000000]={0};
	int d[5000000]={0};
	int dc=0,top=0;
	for(int i=0;i<n;i++){
		int b[300000]={0};
		for(int j=i;j<n;j++){
			b[a[j]]+=1;
			d[dc]=a[j];
			if(b[a[j]]==2){
				while(b[a[j]]==0){
					b[d[dc]]--;
					dc--;
				}
				d[dc]=a[j];
			}
		}
		for(int j=0;j<m;j++){
			c[j]+=b[j];
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
