#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],a2[N];
int rnk[N];
int w[N];
int t[N];
int n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rnk[i]=w[i]=a2[i]=a[i];
	}
	sort(a+1,a+1+n);
	int cnt=unique(a+1,a+1+n)-(a+1);
	for(int i=1;i<=n;i++){
		int p=lower_bound(a+1,a+1+cnt,rnk[i])-a;
		w[p]=a2[i];
		rnk[i]=p;
		t[rnk[i]]++;
	}
//	for(int i=1;i<=n;i++) cout<<rnk[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=cnt;i++) cout<<w[i]<<' ';
//	for(int i=1;i<=n;i++) cout<<t[i]<<' ';
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int sum=0,p=0,tot=t[i];
		for(int j=i-1;j>=1;j--){
			sum+=(w[i]-w[j])*t[j];
			tot+=t[j];
			if(sum>m){
				sum-=(w[i]-w[j])*t[j];
				tot-=t[j];
				p=j;
				break;
			}
		}
//		cout<<i<<' '<<p<<" "<<sum<<endl;
		int tmp=m-sum;
		if(p!=0) tot+=tmp/(w[i]-w[p]);
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
	return 0;
} 
