#include<bits/stdc++.h>//卡了兄弟，一个小时才把T1A掉 
using namespace std;
int n,ans,qq[500005];
long long m,a[500005],s[500005],mina;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mina=min(a[i],mina);
	}
	mina--;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]-=mina,s[i]=s[i-1]+a[i],qq[i]=a[i]==a[i-1]?qq[i-1]:i-1;
	for(int i=1;i<=n;i++){
		//s[j-1]>=s[i]-m
		int l=1,r=qq[i]+1;
		if(a[i]-a[qq[i]]>m){
			ans=max(i-qq[i],ans);
			continue;
		}
		while(l<r){
			int mid=l+r>>1;
			long long res=(qq[i]-mid+1)*a[i];
			if(s[qq[i]]-s[mid-1]+m>=res){
//				ans=max(ans,i-mid+1);
				r=mid;
			}
			else l=mid+1;
		}
		int j=l;
//		int j=lower_bound(s+1,s+n+1,s[qq[i]]-m)-s;
		if(i-j+1>ans){
			ans=i-j+1;
//			printf("[%d , %d]: %lld\n",j,i,s[qq[i]]-s[j-1]);
		}
//		ans=max(i-j+1,ans);
	}
	cout<<ans;
	return 0;
}
