#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long ans=0;
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else if(a[l]>a[r]) a[l]-=a[r],r--;
			else l++,r--;
		}
		else{
			if(a[l]<a[r]) ans+=a[l],a[r]-=a[l],l++;
			else if(a[l]>a[r]) ans+=a[r],a[l]-=a[r],r--;
			else ans+=a[l],l++,r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
