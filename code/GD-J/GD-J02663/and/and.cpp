#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxv=-1,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxv=max(maxv,a[i]);
		if(i==1){
			x=a[i];
		}else{
			x=x&a[i];
		}
	}
	if(m==n){
		cout<<x;
		return 0;
	}
	if(m==1){
		cout<<maxv;
		return 0;
	}
	maxv=-1;
	if(m==2){
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				maxv=max(maxv,a[i]&a[j]);
			}
		}
		cout<<maxv;
		return 0;
	}
	return 0;
}
