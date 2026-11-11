#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=2e5+10;
ll n,x,ans;
char y;
struct sector{
	ll len;
	char c;
};
deque<sector>q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		q.pb({x,y});
	}
	while(q.size()>1){
		sector t1=q.front(), t2=q.back();
		if(t1.c!=t2.c) ans+=min(t1.len,t2.len);
		if(t1.len<t2.len){
			q.pop_front();
			q.pop_back(), q.pb({t2.len-t1.len,t2.c});
		}else if(t1.len==t2.len){
			q.pop_front(), q.pop_back();
		}else{
			q.pop_back();
			q.pop_front(), q.push_front({t1.len-t2.len,t1.c});
		}
	}cout<<ans;
	return 0;
}
/*

*/
