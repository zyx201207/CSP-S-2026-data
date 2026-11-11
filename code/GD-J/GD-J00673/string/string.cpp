#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
ll a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ll l=1,r=n,ans=0;
	while (l<r){
		if (a[l]==a[r] && c[l]==c[r]){
			l++,r--;
			continue;
		} 
		else if (a[l]==a[r]) ans+=a[r],l++,r--;
		else {
			if (a[l]>a[r]){
				if (c[l]!=c[r]) ans+=a[r];
				a[l]-=a[r],r--;
			} 
			else{
				if (c[l]!=c[r]) ans+=a[l];
				a[r]-=a[l],l++;
			} 
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
