#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long a[200009]={},k,max_=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_=max(max_,a[i]);
		if(i==1){
			k=a[i];
		}
		k=k&a[i];
	}
	if(m==1){
		cout<<max_;
		return 0;
	}
	if(m==2){
		long long l=1,maxa=-1;
		while(l<n){
			maxa=max(maxa,a[l]&a[l+1]);
			l++;
		}
		maxa=max(maxa,a[1]&a[n]);
		cout<<maxa;
		return 0;
	}
	if(m==n){
		cout<<k;
		return 0;
	}
	cout<<0;
	return 0;
} 
