#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int sum=a[1];
	cout<<sum;
	for(int i=2;i<=m;i++){
		cout<<a[i]<<" ";
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
