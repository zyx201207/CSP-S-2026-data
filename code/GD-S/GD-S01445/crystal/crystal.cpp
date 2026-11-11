#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define filename "crystal"
const int N=5e5+10;
ll n,m;
ll a[N];
ll vis[310];
int main(){
//	freopen(filename".in","r",stdin);
//	freopen(filename".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool nature_A=1;
	bool nature_B=1;
	ll max_num=-1;
	ll ssumm=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)nature_A=0;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3)nature_B=0;
		max_num=max(max_num,a[i]);
		ssumm+=a[i];
	}
	if(nature_A){
		ll max_answer=(1+(long long)(sqrt(1+8*m)))/2;
		if(max_answer>n){
			cout<<n<<'\n';
		}else{
			cout<<max_answer<<'\n';
		}
		return 0;
	}else if(nature_B){
		sort(a+1,a+n+1);
		ll needs=0;
		bool is_output=0;
		for(int i=2;i<=n;i++){
			needs+=abs(a[i]-a[i-1])*(i-1);
			if(needs>m){
				cout<<i-1<<'\n';
				is_output=1;
				return 0;
			}
		}
		if(!is_output){
			cout<<n<<'\n';
			return 0;
		}
	}else if(n<=5000){
		ll ans=-1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			ll need=0;
			ll answer_now=1;
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				if(a[i]<a[j])continue;
				need+=abs(a[i]-a[j]); 
				if(need>m){
					answer_now--;
					break;
				}
				answer_now++;
			}
			ans=max(ans,answer_now);
		}
		cout<<ans<<'\n';
		return 0;
	}else if(max_num<=100&&n>5000&&m>=1000){
		for(int i=1;i<=n;i++){
			vis[a[i]+100]++;//0~200 ¶ÔÓ¦ -100~100 
		}
//		for(int i=0;i<=200;i++){
//			cout<<vis[i]<<" ";
//		}
		ll ans=-1;
		for(int i=0;i<=200;i++){
			ll sum=0;
			ll cnt=0;
			if(i==0){
				ans=max(vis[0],ans);
				continue;
			}
			ll k=1;
			for(int j=i;j>=0;j--){
				if(j==i){
					cnt+=vis[j];
					continue;
				}
				if(sum+k*vis[j]>m){
					cnt+=((m-sum)/k);
					break;
				}else{
					sum+=k*vis[j];
					k++;
					cnt+=vis[j];
				}
			}
			ans=max(ans,cnt);
//			cout<<ans<<" ";
		}
		cout<<ans<<'\n';
		return 0;
	}else{
		cout<<ssumm<<'\n';
		return 0;
	}
	return 0;
}
//90pts

