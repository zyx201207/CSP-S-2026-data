#include<bits/stdc++.h>
using namespace std;
int n,a[200010]={0};
long long ans=0;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]!=b[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				r--;
				a[l]-=a[r];
			}else if(a[l]<a[r]){
				ans+=a[l];
				l++;
				a[r]-=a[l];
			}else{
				ans+=a[l];
				r--;
				l++;
			}
		}else{
			if(a[l]>a[r]){
				r--;
				a[l]-=a[r];
			}else if(a[l]<a[r]){
				l++;
				a[r]-=a[l];
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
