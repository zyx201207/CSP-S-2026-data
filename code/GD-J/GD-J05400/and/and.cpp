#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200007],ans,sum,cnt,aa;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		aa=max(aa,a[i]);
	}
	if(n<=20) {
		for(int i=1;i<(1<<n);i++){
			sum=-1;	
			cnt=0;
			for(int j=0;(1<<j)<=i;j++){
				if(cnt>=m) break;
				if(i&(1<<j)) {
					cnt++;
					if(sum==-1) sum=a[j];
					else sum&=a[j];	
				}
			}
			if(cnt==m) ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=0;i<n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		sum=a[0];
		for(int i=1;i<n;i++) sum&=a[i];
		for(int i=0;i<n;i++){
			ans=max(ans,sum&a[i]);
		}
		cout<<ans;
		return 0;
	}
	cout<<aa;
	return 0;
}
