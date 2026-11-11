#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int max1=-10000;
		for(int i=1;i<=n;i++){
			if(a[i]>max1) max1=a[i];
		}
		cout<<max1;
	}else if(m==2){
		int max1=-10000;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(a[i]&a[j]>max1) max1=a[i]&a[j];	
			}
		}
		cout<<max1;
	}else if(m==n){
		int max1=a[1];
		for(int i=2;i<=m;i++){
			max1=max1&a[i];
		}
		cout<<max1;
	}else{
		sort(a+1,a+n+1);
		int max1=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			max1=a[i]&max1;
		}
		cout<<max1;
	}
	return 0;
}
