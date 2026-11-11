#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],b,sum;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	b=a[1];
	for(int i=1;i<=k;i++){
		sum+=b&a[i];
		b=b&a[i];
	}
	cout<<sum;
	return 0;
}
