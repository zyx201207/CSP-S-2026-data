#include<bits/stdc++.h>
using namespace std;
int m,n,a[200005],sum=-1,ls;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m;i++){
		ls=a[i];
		for(int j=1+i;j<=m+i;j++){
			ls=ls&a[j];
		}
		sum=max(sum,ls);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

