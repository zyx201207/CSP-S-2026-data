#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(1ll*a[i]*(i-mid)<=m+s[i-1]-s[mid-1]){
				r=mid;
			}
			else {
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
} 
