#include <bits/stdc++.h>
using namespace std;
const int N=2e6+8;
long long a[N],d;
int c,t,n,ll[N],lr[N],rl[N],rr[N],flag[N],tmp=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>c>>t;
	while (t--){
		cin >>n>>d;
		long long ans=0,m=d;
		for (int i=1;i<=n;++i){
			cin >>a[i];
		}
		flag[1]=flag[n-1]=1;
		ll[1]=lr[1]=1;
		rl[1]=rr[1]=2;
		for (int i=2;i<n-1;++i){
			ll[i]=ll[i-1];
			rl[i]=max(rl[i-1],i+2);
			rr[i]=rr[i-1];
			while (ll[i]<i&&a[i+1]-a[ll[i]]>m) ++ll[i];
			while (lr[i]<i-1&&a[i+2]-a[lr[i]+1]>m) ++lr[i];
			while (rl[i]<n&&a[rl[i]]-a[i-1]<=m) ++rl[i];
			while (rr[i]<n&&a[rr[i]+1]-a[i]<=m) ++rr[i];
			flag[i]=(a[i+2]-a[lr[i]]<=m||ll[i]>lr[i]||a[rl[i]]-a[i-1]<=m||rl[i]>rr[i]);
//			if (a[i+2]-a[lr[i]]<=m||ll[i]>lr[i]){
//				
//			}
//			if (a[rl[i]]-a[i-1]>m&&rl[i]>rr[i]) ans+=()
//			if (a[i+2]-a[lr[i]]>m&&ll[i]>lr[i]){
//				int L=
//				ans+=(rr[i]-lr[i])
//			}
			if (lr[i]-ll[i]>1) ++tmp;
			if (rl[i]-rr[i]>1) ++tmp;
		}
		for (int i=2;i<n-1;++i){
//			cerr <<i<<' '<<ll[i]<<' '<<lr[i]<<' '<<rl[i]<<' '<<rr[i]<<' '<<flag[i]<<'\n';
			if (flag[i]==0){
				int op1=i-1,op2=i+1;
				while (op1>1&&flag[op1]) op1--;
				while (op2<=n&&flag[op2]) op2++;
//				ans+=1ll*(lr[i]-ll[i]+1)*(rr[i]-rl[i]+1);
				ans+=1ll*(lr[i]-ll[i]+1)*(rr[i]-rl[i]+1);
			}
		}
//		cerr <<tmp<<'\n';
		cout <<ans<<'\n';
	}
	return 0;
}/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

6
*/

//#include <bits/stdc++.h>
//using namespace std;
//long long a[2000005];
//int main(){
////	freopen("migrate.in","r",stdin);
////	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	int c,t;
//	cin >>c>>t;
//	while (t--){
//		int n;
//		long long m,cnt=0;
//		cin >>n>>m;
//		for (int i=1;i<=n;++i) cin >>a[i];
//		for (int i=1;i<=n;++i){
//			for (int j=i+2;j<=n;++j){
//				int Cnt=0;
//				for (int k=i+1;k<j;++k){
//					if (a[k]-a[i]<=m&&a[j]-a[k]<=m) ++Cnt;
//				}
//				if (a[j]-a[i]>m&&Cnt==2) ++cnt;
////				if (a[j]-a[i]<=m) continue;
////				int l,r,k1,k2;
////				l=i+1,r=j-1;
////				while (l<=r){
////					int mid=(l+r)/2;
////					if (a[mid]-a[i]>m) r=mid-1;
////					else l=mid+1;
////				}
////				k1=r;
////				l=i+1,r=j-1;
////				while (l<=r){
////					int mid=(l+r)/2;
////					if (a[j]-a[mid]>m) l=mid+1;
////					else r=mid-1;
////				}
////				k2=l;
////				if (k1!=i&&k2!=j&&k1-k2==1) ++cnt;
//			}
//		}
//		cout <<cnt<<'\n';
//	}
//	return 0;
//}
