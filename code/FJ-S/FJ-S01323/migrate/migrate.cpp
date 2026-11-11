#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[2000005];
int p[2000005];
int q[2000005];
int fp[2000005];
int fq[2000005];
int ansp[2000005];
int ansq[2000005];
int cnt[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];p[i]=q[i]=cnt[i]=0;
			fp[i]=fq[i]=i;ansp[i]=ansq[i]=1;
		}
		for(int i=1;i<=n;i++){
			int l=1,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[i]-a[mid]<=d)r=mid;
				else l=mid+1;
			}p[i]=l;fq[l]=max(fq[l],i);
			l=i,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(a[mid]-a[i]<=d)l=mid;
				else r=mid-1;
			}q[i]=l;fp[l]=min(fp[l],i);
		}
		for(int i=1;i<n;i++)fp[i]=min(fp[i],fp[i+1]);
		for(int i=n;i>=2;i--)fq[i]=max(fq[i],fq[i-1]);
		for(int i=1;i<=n;i++){
			//cout<<p[i]<<" "<<q[i]<<" "<<fp[i]<<" "<<fq[i]<<endl;
		}
		for(int i=1;i<=n;i++)ansp[q[i]]+=ansp[i];
		for(int i=n;i>=1;i--)ansq[p[i]]+=ansq[i];
		for(int i=1;i<=n;i++)cnt[p[i]]+=ansq[i];
		for(int i=1;i<=n;i++){
			//cout<<ansp[i]<<" "<<ansq[i]<<" "<<cnt[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(q[i]-1>i)
			ans+=cnt[q[i]-1]*ansp[i]; 
		}cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

6 4
-3 0 1 2 3 4

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/


