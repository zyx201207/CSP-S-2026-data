#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[500005],c[300005],d[300005],h[500005],nn;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(c[a[i]]!=0){
			sum[c[a[i]]]--;
			sum[i]++;
		}
		c[a[i]]=i;
		if(a[i]<a[i-1]){
			nn=1;
		}
	}
	if(nn==0){
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
	} 
	else{
			for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		h[i]=i+sum[i];
		d[a[i]]=max(d[a[i]],h[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	}
} 
