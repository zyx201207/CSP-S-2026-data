#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans,cnt;
int a[N],nwa[N];
char c[N],nwc[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	char last=' ';
	for(int i=1;i<=n;i++){
		if(last!=c[i]){
			cnt++;
			last=c[i];
			nwc[cnt]=c[i];
			nwa[cnt]+=a[i];
		}
		else nwa[cnt]+=a[i];
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<nwa[i]<<" "<<nwc[i]<<endl;
//	}
	for(int l=1,r=cnt;l<r;){
		if(nwa[l]>nwa[r]){
			if(nwc[l]!=nwc[r])ans=ans+nwa[r];
			nwa[l]-=nwa[r];
			r--;
		}
		else if(nwa[r]>nwa[l]){
			if(nwc[l]!=nwc[r])ans=ans+nwa[l];
			nwa[r]-=nwa[l];
			l++;
		}
		else if(nwa[r]==nwa[l]){
			if(nwc[l]!=nwc[r])ans+=nwa[l];
			l++,r--;
		}
//		cout<<l<<" "<<r<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
