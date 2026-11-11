#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,ans,sum;
int a[N];
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n; 
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				l++;
				r--; 
			}
			else{
				a[l]-=a[r];
				r--;
			}
		}
		else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--; 
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
