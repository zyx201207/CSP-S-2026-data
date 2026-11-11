#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,d,a[2000001] = {0},dis[2000001] = {0},b[2000001] = {0},c;
int rnxt[2000001] = {0},lnxt[600001] = {0};
bitset<6001>l[6001],r[6001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%lld %lld",&c,&T);
//	c = 11;
	while(T--){
		scanf("%lld %lld",&n,&d);
		for(int i = 1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		a[0] = -2e18;
		a[0]--;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(c<=10){
			int ans = 0;
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=i;j++){
					b[j] = 1;
				}
				for(int j = i+1;j<=n;j++)b[j] = 0;
				for(int j = 1;j<=n;j++)dis[j] = 0;
//				cout<<i<<endl;
				for(int j = i+1;j<=n;j++){
					dis[j] = dis[upper_bound(a,a+1+n,a[j]-d-1)-a]+1;
					int g = max(upper_bound(a,a+1+n,a[j]-d-1)-a,i);
//					cout<<j<<" from: "<<g<<endl;
					int sum = b[g];
					if(dis[g+1]==dis[g] and g+1<j){
						sum+=b[g+1];
						if(dis[g+2]==dis[g] and g+2<j)sum+=b[g+2];
					}
					b[j] = sum;
					if(b[j]==2)ans++;
				}
//				for(int j = 1;j<=n;j++){
//					cout<<dis[j]<<" ";
//				}
//				cout<<endl;
//				for(int j = 1;j<=n;j++){
//					cout<<b[j]<<" ";
//				}
//				cout<<endl;
			}
			cout<<ans<<endl;
//			rnxt[i] = lower_bound(a,a+1+n,a[i]+d+1)-a-1;
			continue;
		}else if(c==11 or c==12){
			int ans = 0;
			for(int i = 1;i<=1;i++){
				for(int j = 1;j<=i;j++){
					b[j] = 1;
				}
				for(int j = i+1;j<=n;j++)b[j] = 0;
				for(int j = 1;j<=n;j++)dis[j] = 0;
				for(int j = i+1;j<=n;j++){
					dis[j] = dis[upper_bound(a,a+1+n,a[j]-d-1)-a]+1;
					int g = max(upper_bound(a,a+1+n,a[j]-d-1)-a,i);
					int sum = b[g];
					if(dis[g+1]==dis[g] and g+1<j){
						sum+=b[g+1];
						if(dis[g+2]==dis[g] and g+2<j)sum+=b[g+2];
					}
					b[j] = sum;
					if(b[j]==2)ans+=n-i+1;
				}
			}
			cout<<ans<<endl;
		}else if(c==13 or c==14){
			int pos = 1,lst = 0,ans = 0;
			for(int i = 1;i<=n;i++){
				while(a[pos]-a[i]<=d and pos<=n)pos++;
				pos--;
				ans+=n-pos;
			}
			cout<<ans<<endl;
		}
//		if(n<=500){
//			cout<<n<<" "<<d/(a[2]-a[1])<<endl;
//			for(int i = 1;i<=n;i++)cout<<a[i]<<" ";
//			cout<<endl;
//		}
	}
	return 0;
}
/*
ez n^3 and ABC,right test and left test done.1557
rh ABC not so ez but n^2/w ok?1612
1617 try n^2/w.
0 1
6 5
1 5 7 12 13 17
ah something went wrong 1645
????still0pts1655
ah.1825
*/
