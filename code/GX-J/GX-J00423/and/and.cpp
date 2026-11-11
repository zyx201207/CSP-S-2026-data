#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,d=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	sort(a+0,a+n);
	//for(int i=0;i<n;i++){
		//cout<<a[i]<<' ';
		//}
	d=a[n-1];
	for(int i=n-1;i>n-1-m;i--){
		//cout<<a[i]<<' ';
		d=(d&a[i]);
		}
	cout<<d;
	return 0;
}























