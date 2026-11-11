#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100+5],maxv;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0)maxv=0;
		if(a[i]>maxv)maxv=a[i];
	}
	cout<<maxv;
	return 0;
}
