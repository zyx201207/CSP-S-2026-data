#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		cin>>a[r]>>c[r];
		if(c[r-1]==c[r]){
			a[r-1]+=a[r];
		}else{
			r++;
		}
	}
	r--;
	long long ans=0;
	while(l<=r){
		if(a[l]==0){
			l++;
			continue;
		}
		if(a[r]==0){
			r--;
			continue;
		}
		if(a[l]>a[r]||(a[l]==a[r]&&c[l]!=c[r])){
			for(long long i=r,k=a[l];k>=1;i--){
				if(a[i]==0){
					continue;
				}
				if(c[i]!=c[l]){
					if(a[i]<=k){
						ans+=a[i];
						k-=a[i];
						a[i]=0;
					}else{
						ans+=k;
						a[i]-=k;
						break;
					}
				}else{
					k-=a[i];
				}
			}
		}else if(a[l]<a[r]){
			for(long long i=l,k=a[r];k>=1;i++){
				if(a[i]==0){
					continue;
				}
				if(c[i]!=c[r]){
					if(a[i]<=k){
						ans+=a[i];
						k-=a[i];
						a[i]=0;
					}else{
						ans+=k;
						a[i]-=k;
						break;
					}
				}else{
					k-=a[i];
				}
			}
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
