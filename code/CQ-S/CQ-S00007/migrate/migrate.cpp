#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int a[5005],R[5005],L[5005];
bool vis[5005]; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			vis[i]=0;
		}
		if (t==13||t==14){
			int len=n/2-1;
			cout<<len*n-(n+2)*len/2<<endl;
			continue;
		}
		if (t==11||t==12){
			if (n<4||!((a[4]-a[1]<2*d)&&(a[3]-a[1]<d))){
				cout<<0<<endl;
				continue;
			}else{
				int len=n/2-1;
				cout<<len*n-(n+2)*len/2<<endl;
				continue;
			}
		}
		for (int i=1;i<=n;i++){
			R[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;//向右能够够到最远的距离 
		}
		for (int i=1;i<=n;i++){
			L[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		}
		ll cnt=0;
		for (int l=1;l+2<=n;l++){
			int r=l+3;
			if (R[l]-L[r]==1){
				vis[l]=1;
				vis[l+1]=1;
				vis[l+2]=1;
			}
		}
		int sum=0;
		for (int i=1;i<=n;i++){
			if (vis[i]){
				sum++;
			}else{
				if (sum!=0){
					sum++;
					int len=sum/2-1;
					cnt+=len*sum-(sum+2)*len/2;
				}
				sum=0;
			}
		}
		if (sum!=0){
			int len=sum/2-1;
			cnt+=len*sum-(sum+2)*len/2;
		}
		cout<<cnt<<endl;
	}
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/

