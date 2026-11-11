#include<bits/stdc++.h>
using namespace std;
long long n,m,o;

int a[500001],b[500001],c[500001];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	a[n]=10000000;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
	int a1=1;	
	for(int s=n-1-j;s>0;s--){
			if(a[j+a1-1]>a[j+a1]){
					b[j]=a[j+a1];
					a[j+a1]=a[j+a1-1];
					a[j+a1-1]=b[j];

				
			}
		}
		
	}
	
	for(int k=0;k<n-1;k++){
		c[k]=a[k+1]-a[k];
		
	}
	
	

	for(int v=0;v<n-1;v++){
		int b1=1;
		for(int h=n-1-v;h>0;h--){
			if(c[v+b1]>c[v+b1-1]){
			
				b[v]=c[v+b1-1];
				c[v+b1-1]=c[v+b1];
				c[v+b1]=b[v];
			}
		}
		
	}
	
	for(int p=n;p>0;p--){
		if(c[p]>m){
			m-c[p];
			o++;
		}
	}
	cout<<o;
	return 0;
}
