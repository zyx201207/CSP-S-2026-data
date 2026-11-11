#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int N=2e5+5;
int n,sum=0;
deque<pair<int,char>> q;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		q.push_back({a,c});
	}
	while(q.size()>1){
		if(q.front().S!=q.back().S)sum+=min(q.front().F,q.back().F);
		if(q.front().F>q.back().F){
			auto t=q.front();
			t.F=q.front().F-q.back().F;
			q.pop_front();
			q.pop_back();
			q.push_front(t);
		}else if(q.front().F<q.back().F){
			auto t=q.back();
			t.F=q.back().F-q.front().F;
			q.pop_front();
			q.pop_back();
			q.push_back(t);
		}else{
			q.pop_front();
			q.pop_back();
		}
	}
	cout<<sum<<endl;
	return 0;
} 
