#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=5e5;
struct Node{
	ll num;
	int cnt;
};
ll n,m;
ll ans=-0x3f3f3f3f3f3f3f3f,cnt=1;
ll a[Maxn+7],f[Maxn+7],nums[Maxn+7];
ll g[Maxn+7];
Node b[Maxn+7];
ll cf[Maxn+7];
bool check(int j,int i){
	if(cf[j]-nums[i-1]*(b[j].num-b[i-1].num)-cf[i-1]<m) return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1].cnt=1,b[1].num=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) b[cnt].cnt++;
		else{
			b[++cnt].cnt++;
			b[cnt].num=a[i];
		}
	}
	cf[1]=0;
	nums[1]=b[1].cnt;
	for(int i=2;i<=cnt;i++){
		cf[i]=cf[i-1]+(b[i].num-b[i-1].num)*nums[i-1];
		nums[i]=nums[i-1]+b[i].cnt;
//		cout<<b[i].num<<" "<<cf[i]<<" "<<nums[i]<<"\n";
	}
	ans=b[1].cnt;
	for(int i=2;i<=cnt;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
//		cout<<r<<" "<<i<<"\n";
		if(r==1){
			ans=max(nums[i],ans);
		}else{
			ll sheng=cf[i]-nums[r-1]*(b[i].num-b[r-1].num)-cf[r-1];
			ans=max(1ll*ans,nums[i]-nums[r-1]+(m-sheng)/(b[i].num-b[r-1].num));
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
