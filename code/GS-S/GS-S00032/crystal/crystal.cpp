#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,r=0;
	cin>>n>>m;
	if(n==0){
		cout<<0;
		return 0;
	}else if(m==0){
		cout<<1;
		return 0;
	}
	long long a2[n],a[n],x1,x2,d=0;
	for(int i=0;i<n;i++){
		cin>>a2[i];
	}
	x1=a2[0];
	x2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a2[j]>x1){
				x1=a2[j];
				x2=j;
			}
		}
		a[n-d-1]=x1;
		a2[x2]=0;
		d++;
		x1=0;
		x2=0;
	}
	long long a1[n+1][m+1];
	for(int x=0;x<n;x++){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			a1[i][j]=0;
		}
	}
	
	for(int i=1;i<=x+1;i++){
		for(int j=a[x]-a[i-1];j<=m;j++){
			a1[i][j]=a1[i-1][j];
			a1[i][j]=max(a1[i][j],a1[i-1][j-a[x]+a[i-1]]+1);
			r=max(a1[i][j],r);
		}
	}

	}
	cout<<r;
} 
