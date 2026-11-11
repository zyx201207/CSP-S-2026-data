#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100011];
int b[100011];
int c[100011];
int f(int m,int s){
	for(int i=1;i<=n;i++){
		if(b[i]==s) return 1;
	}
	return 0;
}
int f1(int m,int s){
	for(int i=1;i<=n;i++){
		if(b[i]==s) return i ;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			if(f(j,a[j])==1){
				for(int l=f1(j,a[j]);l<j;l++){
					b[l]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=0){
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
