#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
#define _for1(i,x,y,z) for(int i=x;i>=y;i-=z)
typedef long long ll;
const int N=6e5;
int n,ans;
ll a[N],m,s[N],sum;
deque<ll> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	_for(i,1,n,1){
		cin>>a[i];
	}sort(a+1,a+n+1);
	_for(i,1,n+1,1){
		ans=max(ans,(int)q.size());
		if(q.front()!=a[i]){
			sum+=q.size()*(a[i]-q.front());
			if(sum>m){
				while(sum>m&&!q.empty()){
					sum-=a[i]-q.back();
					q.pop_back();
				}
			}
		}
		q.push_front(a[i]);
	}cout<<ans;
}
