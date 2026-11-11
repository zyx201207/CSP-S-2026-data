//GZ-J00130 凤冈县第二中学 罗迎甲 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long a[10000001]={},n,m,max1=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		max1=max(max1,a[i]&a[j]);
	}
	}
	cout<<max1;
	return 0;
}
