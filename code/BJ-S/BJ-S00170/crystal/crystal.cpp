#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];
long long ans=0;
void pd(){
	long long l=1,r=2;
	while(r!=n){
		if(d[r]-d[l]<=m){
			ans=max(ans,r-l+1);
			r++;	
		} 
		else{
			if(r-l!=1) l++;
			else{
				r++;
				l++;
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
		d[i]=d[i-1]+(i-1)*d[i];
	}
	pd();
	cout<<ans;
	return 0;
}
