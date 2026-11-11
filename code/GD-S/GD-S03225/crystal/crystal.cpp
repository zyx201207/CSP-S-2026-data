#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],s[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=l+r>>1;
			//求满足条件的下界
			if(a[i]*(i-mid)-s[i-1]+s[mid-1]>m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
//		cout<<"ind:"<<i<<" left:"<<l<<'\n';
		if(a[i]*(i-l)-s[i-1]+s[l-1]>m){
			continue;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
} 
