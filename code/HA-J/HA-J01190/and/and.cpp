#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int a[200000],n,m,mmax;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	if(a[i]||a[i-1]>a[i-1]||a[i-2]>a[i-3]||a[i-4]){
		mmax=a[i];
	}
	cout<<mmax;
	return 0;
}
