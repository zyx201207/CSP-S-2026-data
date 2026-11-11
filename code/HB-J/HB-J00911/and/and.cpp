#include<bits/stdc++.h>
using namespace std;
int a[100000000];
void in(int a[],int n){
	sort(a+1,a+n+1);
}
int main(){
	freopen("and.in","r",stdin);
	//freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	in(a,n);
	int t=a[n];
	for(int i=n;i>n-m;i--){
		t=t&a[i];
	}
	cout<<t;
	return 0;
}
	
	
		
