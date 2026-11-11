#include <bits/stdc++.h>
using namespace std;
deque<pair<int,char> >q;
long long ans;
int n,x;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		q.push_back(make_pair(x,c));
	}
	while(!q.empty()){
		int x1,x2;
		char c1,c2;
		x1=q.front().first;
		c1=q.front().second;
		q.pop_front();
		if(q.empty())break;
		x2=q.back().first;
		c2=q.back().second;
		q.pop_back();
		if(c1==c2&&x1==x2){
			continue;
		}
		if(c1==c2){
			if(x1<x2){
				x2=x2-x1;
				q.push_back(make_pair(x2,c2));
				continue;
			}
			if(x1>x2){
				x1=x1-x2;
				q.push_front(make_pair(x1,c1));
				continue;
			}
		}
		if(x1==x2){
			ans=ans+1ll*x1;
			continue;
		}
		if(x1<x2){
			ans=ans+1ll*x1;
			x2=x2-x1;
			q.push_back(make_pair(x2,c2));
			continue;
		}
		if(x1>x2){
			ans=ans+1ll*x2;
			x1=x1-x2;
			q.push_front(make_pair(x1,c1));
			continue;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
