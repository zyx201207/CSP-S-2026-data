#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100]={0};
long long h=0,x;
long long sum=1,maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0,j=0;
	x=a[0];
	while(i<=j && i<n-1 && j<n-1){
		j++;
		sum++;
		h=h+(a[j]-x)*(sum-1);
		x=a[j];
		while(h>m){
			h=h-(a[j]-a[i]);
			i++;
			sum--;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
