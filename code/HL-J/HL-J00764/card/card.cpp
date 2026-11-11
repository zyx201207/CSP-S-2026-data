#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int maxn=2e6+5;
const int mod=1e9+7;
int a[maxn];
int b[maxn];
int cnt[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int nw=0;
	while(++nw<=n){
		queue<int>q;
		set<int>s;
		for(int i=nw;i<=n;i++){
			q.push(a[i]);
			int si=s.size();
			s.insert(a[i]);
			if(s.size()==si){
				queue<int>q2;
				int j;
				while(j++){
					int nww=q.front();
					q.pop();
					q2.push(nww);
					if(nww==a[i])break;
				}
				while(q.size())q.pop();
				while(q2.size()){
					q.push(q2.front());
					q2.pop();
				}
			}
		}
		while(q.size()){
			b[q.front()]++;
			q.pop();
		}
		s.clear();
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
