#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b[1]=a[1];
	int h=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=a[i-1]&a[i];
		h=max(h,a[i]);
	}
	if(n==m){
		cout<<b[n];
		return 0;
	}
	if(m==1){
		cout<<h;
		return 0;
	}
	h=0;
	for(int i=1;i<n;i++){
		for(int j=i;i<=n;i++){
			h=max(h,a[i]&a[j]);
		}
	}
	cout<<h;
	return 0;
}