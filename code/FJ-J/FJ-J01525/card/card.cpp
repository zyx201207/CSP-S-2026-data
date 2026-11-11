#include<bits/stdc++.h>
using namespace std;
long long n,m;
deque<long long> q;
long long a[200005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=m;j++){
			if(q.empty()){
				q.push_back(a[j]);
				continue;	
			}
			q.push_back(a[j]);
			for(auto k:q){
				if(k==a[j]){
					while(q.front()!=a[j]){
						q.pop_front();
					}
				}
			}
		}
		for(auto k:q){
			ans[k]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
}
