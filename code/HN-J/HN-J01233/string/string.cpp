#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010];
char b[200010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int su=0;
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				l++,r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				su+=(a[r]);
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				su+=a[l];
				l++,r--;
			}
			else{
				su+=(a[l]);
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<su;
	return 0;
}
