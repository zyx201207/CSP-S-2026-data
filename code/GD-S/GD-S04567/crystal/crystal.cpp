#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	deque <int> da;
	ll sum=0;
	ll ans=-1;
	ll k=0;
	for(int i=1;i<=n;i++){
		int len=da.size();
		ll cnt=sum;
		if(len!=1&&!da.empty()){
			sum=sum+(a[i]-a[da.back()])*(len);
		}else{
			sum=0;
		}
		da.push_back(i);
		k++;
		if(sum>m){
			while(sum>m&&!da.empty()){
				sum-=a[i]-a[da.front()];
				da.pop_front();
				k--;
			}
		} 
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
