#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],c[100005];
int lon(int l,int r){
	int s=0,i=l;
	while(i<=r)
		s+=c[i++]*(i-l);
	if(s<=m)return r-l+2;
	else return -1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)c[i]=a[i+1]-a[i];
	int ma=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ma=max(ma,lon(i,j));
		}
	}cout<<ma;
	return 0;
}
