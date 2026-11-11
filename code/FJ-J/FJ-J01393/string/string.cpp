#include<bits/stdc++.h>
using namespace std;
int n,l=1,r;
long long ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}while(1){
		if(l>=r){
			cout<<ans;
			return 0;
		}if(a[r]>0){
			if(a[r]<=a[l]){
				if(c[r]!=c[l]){
					ans+=a[r];
				}a[l]-=a[r],a[r]=0,r--;
				if(a[l]==0) l++;
			}else{
				if(c[r]!=c[l]){
					ans+=a[l];
				}a[r]-=a[l],a[l]=0,l++;
			}
		}else r--;
	}return 0;
}
