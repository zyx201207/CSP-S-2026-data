#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
long long z;
int gz(int xx1,int yy1){
	return xx1>=yy1;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,gz);
	for(int i=1;i<m;i++){
		z=a[0];
		z=z&a[i];
	}
	cout<<z; 
	return 0;
} 
