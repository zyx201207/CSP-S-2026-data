#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int n,ans;
long long m;
long long a[maxn],s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-s[i-1]+s[mid-1]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
