#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,len,ans,cur,sum,lst,num;
ll a[N],pre[N],dpre[N];
char c[N];
map<char,ll> mp;
vector<pair<char,ll> > v,v2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld %c",&a[i],&c[i]),len+=a[i],pre[i]=pre[i-1]+a[i];
	for(ll i=n;i>=1;i--)dpre[i]=dpre[i+1]+a[i];
	for(ll i=1,l=0;i<=n;i++){
		if(i!=1&&c[i]!=c[i-1])v.push_back({c[i-1],pre[i-1]-pre[l]}),l=i-1;
		if(pre[i]>=(len>>1ll)){
			v.push_back({c[i],(len>>1ll)-pre[l]});
			break;
		}
	}for(ll i=n,l=n+1;i>=1;i--){
		if(i!=n&&c[i]!=c[i+1])v2.push_back({c[i+1],dpre[i+1]-dpre[l]}),l=i+1;
		if(dpre[i]>=(len>>1ll)){
			v2.push_back({c[i],(len>>1ll)-dpre[l]});
			break;
		}
	}cur=0;
	for(auto &[c,x]:v){
		sum=num=0;
		if(lst){
			num+=lst;
			if(v2[cur].first==c)sum+=lst;
			if(num>x){
				lst=num-x,num=x;
				if(v2[cur].first==c)sum-=lst;
			}else cur++;
		}while(cur<v2.size()&&x>num){
			num+=v2[cur].second;
			if(v2[cur].first==c)sum+=v2[cur].second;
			if(num>x){
				lst=num-x,num=x;
				if(v2[cur].first==c)sum-=lst;
				break;
			}cur++;
		}ans+=x-sum;
	}printf("%lld",ans);
	return 0;
}

