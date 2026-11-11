#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans=-1,maxn=-1,mm;
bool cmp(int l,int r){
	return l>=r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1) mm=a[i];
		else mm=mm&a[i];
	}
	if(n<=2000){
		if(m==1){
			cout<<maxn;
			return 0;
		}
		if(m==n){
			cout<<mm;
			return 0;
		}
		if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}
		if(m==3){
			for(int i=1;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					for(int k=j+1;k<=n;k++){
						ans=max(ans,a[i]&a[j]&a[k]);
					}
				}
			}
			cout<<ans;
		}
		if(m==5){
			for(int i=1;i<n-3;i++){
				for(int j=i+1;j<n-2;j++){
					for(int k=j+1;k<n-1;k++){
						for(int p=k+1;p<n;p++){
							for(int q=p+1;q<=n;q++){
								ans=max(ans,a[i]&a[j]&a[k]&a[p]&a[q]);
							}
						}
					}
				}
			}
			cout<<ans;
		}
		return 0;
	}
	if(m==n){
		cout<<mm;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
