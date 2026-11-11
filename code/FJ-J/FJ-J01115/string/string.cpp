#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long n,a[200005],len,cur,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		long long ll=a[i-1]+1,lr=a[i];
		long long rl=len-lr+1,rr=len-ll+1;
		if(ll>=ceil(len/2.0)) break;
		int rlidx=max(upper_bound(a+1,a+n+1,rl)-a,1ll),rridx=min(upper_bound(a+1,a+n+1,rr)-a,n);
//		if(a[rlidx-1]==rl) rlidx--;
//		if(a[rridx-1]==rr) rridx--;
//		cout<<ll<<" "<<lr<<" "<<rl<<" "<<rr<<"\n";
		for(int j=rlidx;j<=rridx;j++){
			if(c[j]==c[i]) continue;
			ans+=min(rr,a[j])-max(rl,a[j-1]+1)+1;
		}
	}
	cout<<ans;
	return 0;
}

