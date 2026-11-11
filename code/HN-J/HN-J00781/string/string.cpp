#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int l=0,r=n-1;
	int ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				ans+=a[r];
				a[l]=0;
				a[r]=0;
				r--;
				l++;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		else if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				a[l]=0;
				a[r]=0;
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
