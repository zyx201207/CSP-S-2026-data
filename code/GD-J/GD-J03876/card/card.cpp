#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],b[100000],c[100000],x,y; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=1;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=x;k++){
			b[k]=0;
		}
		x=1;
		for(int j=i;j<=n;j++){
			y=1;
			for(int k=1;k<=j;k++){
				if(b[k]==a[j]&&y==1){y=0;k++;x=k;} 
				if(y==0){b[k]=0;}
			}
			if(y==1){b[x]=a[j];x++;}
		}
		for(int k=1;k<=x;k++){
			c[b[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
