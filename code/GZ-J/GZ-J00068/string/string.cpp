//GZ-J00068，阮辰允，贵阳市白云区华师一学校
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,sum,ans;
pair<int,char> x[200001];
deque<pair<int,char> > lh,rh;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].first>>x[i].second;
		l+=x[i].first;
	}
	int num=l>>1ll;
	for(int i=1;i<=n;i++){
		sum+=x[i].first;
		if(sum>num){
			if(num+x[i].first!=sum)
			    lh.push_back({x[i].first+num-sum,x[i].second});
			break;
		}
		else{
			lh.push_back(x[i]);
		}
	}
	sum=0;
	for(int i=n;i>=1;i--){
		sum+=x[i].first;
		if(sum>num&&num+x[i].first!=sum){
			if(num+x[i].first!=sum)
			    rh.push_back({x[i].first+num-sum,x[i].second});
			break;
		}
		else{
			rh.push_back(x[i]);
		}
	}
	while(lh.size()&&rh.size()){
		auto u=lh.front(),v=rh.front();
		lh.pop_front(),rh.pop_front();
		if(u.second!=v.second){
			ans+=min(u.first,v.first);
		}
		if(u.first<v.first){
			rh.push_front({v.first-u.first,v.second});
		}
		else if(u.first>v.first){
			lh.push_front({u.first-v.first,u.second});
		}
	}
	cout<<ans;
	return 0;
} 
