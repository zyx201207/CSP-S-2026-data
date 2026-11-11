#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],s[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){ 
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
//	cout<<m<<' '<<a[3845]<<' '<<a[3846]<<' '<<a[3847]<<'\n';
//	cout<<s[3846]+3845*a[3846];
	int ans=1;
	for(int i=2;i<=n;++i){
		int res=1,st=i;
		while(a[i+1]==a[i]){
			++i; ++res;
		}
//		cout<<i<<'\n';
		
//		int cur=0;
//		for(int j=st-1;j>=1;--j){
//			if(cur-a[j]+a[st]>m) break;
//			res++;
//			cur+=-a[j]+a[st];
//		}
//		ans=max(ans,res);
		
		
		
		int l=1,r=st-1;
		while(l<r){
			int mid=l+r>>1;
			if(-(s[st-1]-s[mid-1])+(st-mid)*a[st]<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
//		cout<<l<<"\n\n";
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
} 
