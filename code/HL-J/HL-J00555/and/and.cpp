#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0,j=0,x=0;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
		for(int i=0;i<n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;}
	if(m==2){
		for(int i=0;i<n;i++)for(int j=i;j<n;j++)if(i!=j)maxn=max(maxn,(a[i] & a[j]));
		cout<<maxn;
		return 0;}
	for(int i=0;i<n;i++){
		j++;
		x&=a[i];
		if(j>m)x^=a[i-j];
		maxn=max(x,maxn);}
	cout<<maxn;
	return 0;}
