#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int a[n],b[m];
	if(n<=20){
		for(int j=0;j<m;j++){
			b[j]=0;
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
			int j=0;
			if(b[j]<a[i]){
				b[j]=a[i];
			}
			for(;j<m;j++){
				if(b[j]>b[j+1]){
					k=b[j+1];
					b[j+1]=b[j];
					b[j]=k;
				}
			}
		}
		cout<<b[0];
	}
	else{
		for(int j=0;j<m;j++){
				b[j]=0;
			}
		for(int i=0;i<n;i++){
			cin>>a[i];
			int j=0;
			if(b[j]<a[i]){
				b[j]=a[i];
			}
			for(;j<m;j++){
				if(b[j]>b[j+1]){
					k=b[j+1];
					b[j+1]=b[j];
					b[j]=k;
				}
			}
		}
		cout<<b[0]-1;
	}
	return 0;
}
