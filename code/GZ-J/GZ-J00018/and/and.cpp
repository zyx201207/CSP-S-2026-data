//GZ-J00018 金沙县第三中学  孟彧臣 
#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,a[100000],b[100000],c;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
		b[i]=a[i] and a[j];
		}
	}
	for(int i=0;i<n;i++){
		c=b[i];
		if(c<b[i]){
			c=b[i];
		}
	cout<<c;
	return 0;
}
}
