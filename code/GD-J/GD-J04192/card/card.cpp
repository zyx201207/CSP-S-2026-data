#include <bits/stdc++.h> 
using namespace std;
#define ll long long

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	vector<ll> a(N+1,0);
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	
	vector<deque<int>> p(M+1,deque<int>());
	for(int i=1;i<=N;i++){
		p[a[i]].push_back(i);
	}
	
	vector<ll> pre(N+1,1);
	for(int i=1;i<=N;i++){
		for(int j=i;j<=M;j++){
			while(p[j].front()<i && !p[j].empty()) p[j].pop_front();
		}
		vector<deque<int>> tp=p;
		for(int j=i;j<=N;j++){
			if(tp[a[j]].size()<=1) continue;
			while(tp[a[j]].front()<j) tp[a[j]].pop_front();
			int l=tp[a[j]].front();
			int r=tp[a[j]].back();
			pre[l]-=1;
			pre[r]+=1;
			j=r;
		}
	}
	
	vector<ll> ans(M+1,0);
	ll add=0;
	for(int i=1;i<=N;i++){
		add+=pre[i];
		ans[a[i]]+=add;
	}
	for(int i=1;i<=M;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
