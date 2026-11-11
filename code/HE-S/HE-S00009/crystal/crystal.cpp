#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int n,m;
int ans=LLONG_MIN;
//bool f(int mid){
//	int cnt=1;
//	int cntm=m;
//	for(int i=mid-1;i>=1;i--){
//		if(cntm-(a[mid]-a[i])>=0){
//			cntm=cntm-(a[mid]-a[i]);
//			cnt++;
//		}else{
//			break;
//		}
//	}
//	if(cnt>1){
////		ans=max(ans,cnt);
//		return true;
//	}
//	return false;
//}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		int tmp=1;
		int res=LLONG_MIN;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				tmp++;
			}else{
				res=max(res,tmp);
				tmp=1;
			}
		}
		cout<<res<<'\n';
		return 0;
	}
//	int l=1,r=n;
//	while(l<=r){
//		int mid=(l+r)/2;
//		if(f(mid)){
////			ans=mid;
//			l=mid+1;
//		}else{
//			
//			r=mid-1;
//		}
//	}
//	int cnt=0;
	for(int i=1;i<=n;i++){
		int cntm=m;
		int cnt=0;
		for(int j=i;j>=1;j--){
			if(cntm-(a[i]-a[j])>=0){
				cntm=cntm-(a[i]-a[j]);
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
}
