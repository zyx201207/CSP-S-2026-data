#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll sum[N];
queue<ll> q;
ll maxn;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		while(true){
			ll total=sum[i]-sum[i-q.size()];
			if(total<=m){
				q.push(a[i]);
				ll len=q.size();
				maxn=max(maxn,len);
				break;
			}else{
				q.pop();
			}			
		}
		//cout<<sum[i]<<" "<<total<<endl;
	}
	
	while(q.size()){
		q.pop();
	}
	
	q.push(a[n]);
	for(int i=n;i>=2;i--){
		while(true){
			ll total=sum[i+q.size()-1]-sum[i];
			if(total<=m){
				q.push(a[i]);
				ll len=q.size();
				maxn=max(maxn,len);
				break;
			}else{
				q.pop();
			}			
		}
		//cout<<sum[i]<<" "<<total<<endl;
	}	
	cout<<maxn;
	return 0;
}
