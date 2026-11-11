#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int n,m,maxn=-1,kksk,kkks,snum;
int a[N],dp[N],tf;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	tf=true;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i){
			tf=false;
		}
	}
	if(tf){
		for(int i=1;i<=n;++i){
			if(snum+a[i]>m){
				cout<<i;
				break;
			}
			snum+=a[i];
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		snum+=a[n]-a[i];
	if(snum<=m){
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
//		cout<<i<<endl;
		int sum=m;
		for(int j=i+1;j<=n;++j){
			int need=abs((a[j]-a[j-1])*(j-i));
			if(sum<need)
				break;
			sum-=need;
//			cout<<j<<' '<<sum<<' '<<need<<endl;
//			cout<<"a["<<j<<']'<<a[j]<<" a["<<j-1<<"]"<<a[j-1]<<endl;
			dp[j]=max(j-i+1,dp[j]); 
		}
	}
	for(int i=1;i<=n;++i){
		maxn=max(maxn,dp[i]);	
	}
	cout<<maxn;
	return 0;
}
/*
差值最小
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

上一项的数字+之前所经历的 
*/
