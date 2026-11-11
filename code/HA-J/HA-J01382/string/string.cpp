#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0,nm=0;
	cin>>n;
	int m[n],b[n];
	char a[n];
	for(int i=1;i<=n;i++){
		cin>>m[i-1];
		cin>>a[i-1];
	} 
	for(int i=1;i<=n;i++){
		b[i-1]=int(a[i-1]);
	}
	for(int i=0;i<=n/2-1;i++){
		if(b[i]!=b[n-i]){
			if(m[i]>=m[n-i]){
				k=k+m[n-i];
			}else{
				k=k+m[i];
			}
		}
//		if(b[i]=b[n-i] and m[i]!=m[n-i]){
//			if(m[i]>m[n-i]){
//				k=k+m[i]-m[n-i];
//			}else{
//				k=k+m[n-i]-m[i];
//			}
//		}
	}
	cout<<k;
	return 0;
}
