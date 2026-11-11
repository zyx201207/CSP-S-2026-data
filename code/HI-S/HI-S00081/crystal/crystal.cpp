#include<bits/stdc++.h>
using namespace std;
int n,ans,smax=0;
long long m,a[500005];
bool special(){
	long long d=a[1]-a[0];
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=d) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if(special()){
		long long d=a[1]-a[0];
		for(int i=1;i<n;i++){
			if(i*(i+1)/2*d>=m){
				ans=i;
				break;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<n;i++){
			long long k=m;
			ans=0;
			for(int j=i-1;j>=0;j--){
				if(k>=a[i]-a[j]){
					k=k-(a[i]-a[j]);
					ans+=1;
				}
			}
			if(ans>smax) smax=ans;
		}
		cout<<smax+1;	
	}
	return 0;
}
