#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
long long m,sum;

bool pan(int x){
	for(int i=1;i<x;i++){
		for(int j=1;j<i;j++){
			sum+=(a[x]-a[i]);
            if(sum<=m) return true;
		}
	}
	return false;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(pan(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
} 
