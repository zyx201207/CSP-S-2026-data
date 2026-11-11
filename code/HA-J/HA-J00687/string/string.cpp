#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],cnt,tot,ans,l,r,pre;
string s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		tot+=a[i];
	}
	int l=1;r=n;
	while(cnt<(tot/2)&&l<r){
		cnt+=min(a[l],a[r]);
		int siz=cnt-pre;
		a[l]-=siz;
		a[r]-=siz;
		if(s[l]!=s[r]){
			ans+=siz;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
		pre=cnt;
	}
	cout<<ans;
	return 0;
}
