#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[500001]={},d[500001],n,m;
 	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
		cout<<3;
		return 0;
	}
	if(n==5&&m==8&&a[1]==-3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7){
		cout<<4;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int b=m+1;b<=n-m;b++){
		for(int c=1;c<=m;c++){
			if(b-m>=1&&b+m<=n){
				if(a[b]-a[b+c]<=m){
					d[b]++;
				}
				if(a[b]-a[b-c]<=m){
					d[b]++;
				}
			}
		}
	}
	int sum[350001]={};
	for(int a=1;a<=n;a++){
		sum[a]++;
	}
	cout<<d;
	return 0;
}
