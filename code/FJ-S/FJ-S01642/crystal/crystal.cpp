#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans;
int n,m;	
int energy(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=x-a[i]; 
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	int l=1,r=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	while(l<=r){
		int mid=l-(l-r)/2;
		int s=0;
		if(energy(mid)>=0){
			for(int i=1;i<=n;i++){
				if(mid>a[i]) s++;
			}	
		}	
		if(energy(mid)>m){
			r=mid-1;
		}
		if(energy(mid)<m){
			l=mid+1;
		}
		ans=max(s,ans);
	}
	cout<<ans;
	return 0;
} 
