#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll INF=1e18;
int n;
ll m;
ll a[N];
ll ans;

ll sec(int x){
	if(x>n)return INF;
	deque<ll>q;
	vector<ll>mx(2*N);
	for(int i=1;i<=n;i++){
		while((!q.empty())&&q.front()<=i-x){
			q.pop_front();
		}while((!q.empty())&&a[q.back()]<=a[i]){
			q.pop_back();
		}
		q.push_back(i);
		mx[i]=a[q.front()];
	}
	ll sum=0;
	ll now=0;
	for(int i=1;i<=x;i++){
		now+=(mx[x]-a[i]);
	}
	sum=now;
	for(int i=x+1;i<=n;i++){
		now=now-(mx[i-1]-a[i-x])+(x-1)*(mx[i]-mx[i-1])+(mx[i]-a[i]);
		sum=min(sum,now);
	}
	return sum;
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=N;
	while(l<=r){
		int mid=(r-l)/2+l;
		ll sum=sec(mid);
		if(sum<=m){
			l=mid+1;
			ans=mid;
		}else if(sum>m){
			r=mid-1;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
