//GZ-J00235 张哲睿 贵阳市新世界学校 
#include<bits/stdc++.h>
using namespace std;
struct N{
	int l=0,r=0;
}b[600001];
int n,m,a[600001],sum[600001]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]].l==0){
			b[a[i]].l=i;
		}
		b[a[i]].r=i;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			i=b[a[i]].r;
			sum[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
