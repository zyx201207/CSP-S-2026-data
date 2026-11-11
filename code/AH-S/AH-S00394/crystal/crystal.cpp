#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define int long long
#define x first
#define y second
const int mod=1e9+7;
const int N=5e5+50;
const int M=1e5+50;
#define endl '\n'
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
int a[N]={};
int sum[N]={};
bool check(int mid){
	for(int i=mid;i<=n;i++){
		int val=a[i];
		int val1=sum[i-1]-sum[i-mid];
		if((mid-1)*val-val1<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

