#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,maxn=-1;
	cin>>n>>m;
	int a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1) maxn=0;
	if(m==n){
		for(int i=1;i<n;i++)
		a[i]=a[i]&a[i-1];
		maxn=a[n-1];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++)
			if(a[i]&a[j]>maxn) maxn=a[i]&a[j];
		}
	}
	if(m==n-1){
		int b[n+2];
		for(int i=0;i<n;i++) b[i]=a[i];
		for(int i=1;i<n-1;i++){
			a[i]=a[i]&a[i-1];
		}
		int k=a[n-2];
		for(int i=2;i<n;i++){
			b[i]=b[i]&b[i-1];
		}
		int d=b[n-1];
		maxn=max(k,d);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
