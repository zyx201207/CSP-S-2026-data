#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],m,d=0;
void po(int j,int z,int c){
	if(c==m){
		d=max(z,d);
		return;
	}
	for(int i=j;i<n;i++){
		po(i+1,z&a[i],c+1);
	}
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-m+1;i++){
		po(i+1,a[i],1);
	}
	cout<<d;
	return 0;
}
