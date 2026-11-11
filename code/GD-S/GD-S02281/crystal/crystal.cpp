#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
//	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=-1e12-5,r=1e12+5;
	ll awa=0,ans=0;
	while(l+1<r){
		ll mid=(l+r)/2;//能量水晶满足什么数值让整体答案最大化 
		ans=0;//要充能多少能量 
		for(int i=1;i<=n;i++){
			if(a[i]<=mid){
				ans+=mid-a[i];
			}
		//	cout<<ans<<" ";
		}
	//	cout<<"\n";
	//	cout<<l<<" "<<r<<"\n";
		if(ans<m){
			awa=mid;
			l=mid; 
		}
		else if(ans>m){
			r=mid;
		}
		else if(ans==m){
			awa=mid; 
			break;
		}
	}
//	cout<<l<<" "<<r<<"\n";
//	cout<<ans<<" "<<m<<"\n";
	ll cnt=0;//最终有几个 
	for(int i=1;i<=n;i++){
		if(a[i]<=awa) cnt++;
	}
	cout<<cnt;
} 
