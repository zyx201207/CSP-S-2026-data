#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200005;
int n,ans,a[MAXN],cnt,s[MAXN],p[MAXN]; 
char c[MAXN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
		cnt+=a[i];
	}
	for(int i=n;i>=1;i--)
		p[i]=p[i+1]+a[i];
	int l=1,r=n,sum=0;
	while(l<r){
		if(c[l]==c[r]){
			if(cnt%2==0){
				if(a[l]>a[r])
					ans+=a[l]-a[r],a[r-1]-=a[l]-a[r];
				else
					ans+=a[r]-a[l],a[l+1]-=a[r]-a[l];
			}
			else{
				if(a[l]>a[r])
					ans+=a[l]-a[r]-1,a[r-1]-=a[l]-a[r],a[r-1]--;
				else if(a[l]<a[r])
					ans+=a[r]-a[l]-1,a[l+1]-=a[r]-a[l],a[l+1]--;
			}
		}
		else{
			if(a[l]>cnt/2 || a[r]>cnt/2){
				ans+=cnt/2;
			}
			else{
				if(a[l]>a[r])
					a[r-1]-=a[l]-a[r];
				if(a[r]>a[l])
					a[l+1]-=a[r]-a[l];
				ans+=max(a[l],a[r]);
			}
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
