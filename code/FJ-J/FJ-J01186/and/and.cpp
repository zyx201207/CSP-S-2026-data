#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005]={0};
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int k=a[1],c1=a[1],c2=a[2],c3=a[3];
	for(int i=1;i<=3;i++){
		for(int j=2;j<=m;j++){
			k=k&a[j+1];
			c1=c1&a[j];
			c2=c2&a[j+1];
			c3=c3&a[j+1];
		}
	}
	int sum=max(k,c1);
	sum=max(sum,c2);
	sum=max(sum,c3);
	cout<<sum;
	return 0;
}
