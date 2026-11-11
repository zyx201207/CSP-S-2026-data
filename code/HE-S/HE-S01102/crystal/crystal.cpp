#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[50005]={0},b[50005]={0},c[50005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[2]-a[1];
	for(int i=2;i<n;i++){
		b[i]=b[i-1]+(a[i+1]-a[i]);
	}
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	long long e=b[1];
	long long f=0;
	int k=0;
	for(int i=2;i<n;i++){
		f=b[i];
		for(int j=i-1;j>=1;j--){
			f=f+j*c[j+1];
		}
		if(f>=e && f<=m){
				e=f;
				k=i+1;
			} 
	}
	if(k==0 && e<=m){
		k=2;
	}	
cout<<k;
return 0;
} 
