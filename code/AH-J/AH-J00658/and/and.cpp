#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000010],mx=INT_MIN,mx2=INT_MIN;
struct ss{
	int num,ma;
}; 
ss d[2000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;int ssss=0;
	for(int i=1;i<=n;i++){cin>>a[i];mx2=max(mx2,a[i]);d[i].num=a[i];}
	if(m==1){cout<<mx2;return 0;}
	for(int i=1;i<=n;i++)d[i].ma=1;
	d[1].num=a[1];
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(d[i].ma+d[j].ma<=m){
				d[i].num=max(d[i].num,d[j].num&a[i]);
				if(d[i].num==(d[j].num&a[i]))ssss=d[j].ma+d[i].ma;
			}
		}
		d[i].ma=ssss;
	}
	for(int i=1;i<=n;i++){
		if(d[i].ma==m-1)mx=max(d[i].num,mx);
	}
	cout<<mx;
	return 0;
}
