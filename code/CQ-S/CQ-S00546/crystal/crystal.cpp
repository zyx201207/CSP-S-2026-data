#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[514514],sum[514514],c[514514],ans=1,pre[514514],summ[514514],prea[514514];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		prea[i]=prea[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=1e18;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+c[i]*(i-1);
		summ[i]=summ[i-1]+c[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+sum[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<' ';
//	}
	for(int i=2;i<=n;i++){
//			cout<<"!!";
		if(sum[i]<=m){
			ans=max(ans,i);
			continue;
		}
//		cout<<"!"<<sum[i]-m<<' ';
		int fll=0;
		for(int j=1;j<=n;j++){
//			cout<<a[i]*j-prea[j]<<' ';
			if(a[i]*j-prea[j]+j>sum[i]-m){
				fll=j-1;
				break;
			}
		}
//		cout<<fll<<'\n';
		if(i-fll-1<ans){
			break;
		}
		else ans=i-fll-1;
//		int id=upper_bound(sum+1,sum+n+1,sum[i]-m-pre[i])-sum-1;
//		int idd=lower_bound(sum+1,sum+n+1,sum[id])-sum-1;
//			cout<<id<<' '<<idd<<'\n';
//		if(id-idd+1>0) cout<<"!!!!!!!!!!!!!!!";
//		if(i-id+1+id-idd-1>ans){
//			cout<<ans<<"->"<<i-id+1+id-idd-1;
//		}
//		ans=max(ans,i-id+1+id-idd-1);
//		cout<<
	}
	cout<<ans;
//	int x=1,y=n-1,fl=0;
//	
//	if(x>y) cout<<0<<'\n';
//	else cout<<y-x+1<<'\n';
//	sort(sum+1,sum+n);
//	int ans=1,summ=0;
//	for(int i=1;i<n;i++){
//		if((summ+=sum[i])>m){
//			break;
//		}
//		ans++;
//	}
////	sort(sum+2,sum+n+1);
////	int ans=1,summ=0;
////	for(int i=2;i<=n;i++){
////		if((summ+=sum[i])>m){
////			break;
////		}
////		ans++;
////	}
//	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7


*/
/*
315275
*/
