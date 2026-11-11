#include"bits/stdc++.h"
using namespace std;
long long n,a[200005],ans;
char b[200005];
deque <pair<int,char> > q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		q.push_back({a[i],b[i]});
	}
	while(!q.empty()){
		int u=q.front().first,v=q.back().first;
		char l=q.front().second,r=q.back().second;
		if(l!=r){
			if(u>v){
				ans+=v;
				q.pop_front();
				q.pop_back();
				q.push_front({(u-v),l});
			}
			else if(v>u){
				ans+=u;
				q.pop_front();
				q.pop_back();
				q.push_back({(v-u),r});
			}
			else{
				ans+=v;
				q.pop_front();
				q.pop_back();
			}
		}else{
			q.pop_front();
			q.pop_back();
			if(u>v)q.push_front({abs(u-v),l});
			else q.push_back({abs(u-v),l});
		}
	}
	cout<<ans;
	return 0;
}
