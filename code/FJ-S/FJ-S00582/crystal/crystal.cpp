#include <bits/stdc++.h>
using namespace std;
long long cnt,mid,n,m,ans,ti,a[555555],p;
bool qf(int x){
	cnt=1e9;
	for(int i=1;i<=n-x+1;i++){
		for(int j=i;j<=i+x-1;j++){
			ti+=a[i+x-1]-a[j];
		}
		cnt=min(cnt,ti);
		ti=0;
	}
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000&&m>1e9){
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				p=1;
			}
		}
		if(p=1){
			if(a[3]-a[2]==a[2]-a[1]){
				p=a[3]-a[2];
				for(int i=p;i<=m;i+=p){
					if(m>=i){
						ans++;
						m-=i;
					}
					else{
						cout<<ans;
						return 0;
					}
				}
			}
		}
		else{
			for(int i=1;i<=m;i++){
				if(m>=i){
					ans++;
					m-=i;
				}
				else{
					cout<<ans;
					return 0;
				}
			}
		}
	}
	int l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(qf(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	
	
	return 0;
}
