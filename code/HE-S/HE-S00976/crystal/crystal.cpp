#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],ans=0,m2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1,r=1e13,mid=(l+r)/2,sum=0,up=0,dn=0;
	while(l<=r){
		mid=(l+r)/2;
		m2=m;
		sum=0;
		for(int i=1;i<=n;i++){
			if(mid==a[i]){
				sum++;
				continue;
			}
			if(mid<a[i])
				dn++;
			else{
				if(m2>=mid-a[i]){
					m2-=mid-a[i];
					sum++;
				}else{
					up++;
				}
			}
		}
		if(dn>up)l=mid+1;
		else r=mid-1;
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
} 
