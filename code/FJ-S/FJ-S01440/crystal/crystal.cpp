#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

long long n,m,a[500010],sum[500010]; 

bool cmp(long long A,long long B){
	return A<B;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} sort(a+1,a+1+n,cmp);
	
	sum[0]=0;
	for(int i=0;i<n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	int MAX=0;
	for(int i=1;i<=n;i++){
		while(a[i+1]==a[i] && i+1<=n)i++;
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(mid*a[i]-(sum[i-1]-sum[i-mid-1])<=m){
				l=mid;
			} else {
				r=mid;
			}
		}
		if(l>MAX)MAX=l;
	}
	cout<<MAX+1;
	
	return 0;
}
