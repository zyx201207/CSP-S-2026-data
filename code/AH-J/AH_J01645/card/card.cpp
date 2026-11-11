#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,x;
long long a[300005],b[500005];
deque<long long> pq;
deque<long long> p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			long long k=b[j];
			while (!p.empty()){
				long long t=p.front();
				pq.push_back(p.front());
				p.pop_front();
				if (t==k){
					while(!p.empty()){
						p.pop_back();
					}
				}
			}
			while(!pq.empty()){
				p.push_back(pq.front());
				pq.pop_front();
			}
			p.push_back(k);
		}
		while (!p.empty()){
			a[p.front()]++;
			p.pop_front();
		}
	}
	for (int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
