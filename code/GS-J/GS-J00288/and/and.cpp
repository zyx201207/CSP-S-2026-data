#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
	}else if(m==2){
		long long ans=-1e9;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(a[i]&a[j]>=ans){
					ans=a[i]&a[j];
				}
			}
		}cout<<ans;
	}
	return 0;
}
