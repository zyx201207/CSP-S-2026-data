#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
bool check(int x){
	int res=0;
	int k=upper_bound(a+1,a+1+n,x)-a,cnt=0;
	for(int i=k-1;i>=1;i--){
		res+=x-a[i];
		cnt++;
		if(res>m){
			cnt--;
			break;
		}
	}
//	cout<<x<<' '<<cnt<<'\n';
	if(cnt<ans) return 0;
	ans=cnt;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	bool ok1=1,ok2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ok1&&a[i]!=i) ok1=0;
		if(ok2&&i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ok2=0;
	}
	if(ok1){
		int s=0,res=0;
		for(int i=1;i<=n;i++){
			s+=a[i];
//			cout<<s<<'\n';
			if(s>m) return cout<<i,0;
		}
	}
	if(ok2){
		int s=0,df=a[2]-a[1];
		for(int i=1;i<=n;i++){
			s+=i;
			if(s*df>m) return cout<<i,0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n];i++){
		if(!check(i)) return cout<<ans,0;
	}
	cout<<ans;
	return 0;
}

