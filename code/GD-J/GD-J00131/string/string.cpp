#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>=a[r]){
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else{
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0;
				l++;
			} 
		}else{
			if(a[l]>=a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
			}else{
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
