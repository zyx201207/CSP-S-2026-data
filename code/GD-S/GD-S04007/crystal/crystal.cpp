#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],d[500005],s[500005],b[500005];
int n,m;
int check(int l,int r){
	//cout << " " << l << " " << r << " " << d[r]-d[l]-(l-1)*s[l]+(l-1)*s[r] << " "; 
	return d[r]-d[l]-(l-1)*s[l]+(l-1)*s[r];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i+1]-a[i];
	b[n]=0;
	for(int i=n;i>=1;i--)s[i]=s[i+1]+b[i];
	for(int i=2;i<=n;i++)d[i]=d[i-1]+(i-1)*s[i-1]-(i-1)*s[i];
	//for(int i=1;i<=n;i++)cout << s[i] << " ";
	//cout << "\n";
	//for(int i=1;i<=n;i++)cout << d[i] << " "; 
	//cout << "\n";
	int ans=0; 
	for(int i=1;i<=n;i++){
		int l=1,r=i,anss=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)<=m)r=mid-1,anss=i-mid+1;
			else l=mid+1;
			//cout << anss << " ";
		}
		ans=max(anss,ans);
		//cout << "\n"; 
	}
	cout << ans;
}
/*
for(int l=r;l>=1;l--){
			int k=;
			cout << " " << l << " " << r << " " << k; 
			if(k>m)break;
			ans=max(ans,r-l+1);
		}
		cout << "\n";
*/
