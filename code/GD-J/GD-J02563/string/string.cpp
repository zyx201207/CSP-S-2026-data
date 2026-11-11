#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str{
	int len;
	char ch;
};
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	deque<str> q;
	while(n--){
		int len;
		char ch;
		cin >> len >> ch;
		q.push_back({len,ch});
	} 
	while(q.size()>1){
		str l=q.front();
		str r=q.back();
		q.pop_front();
		q.pop_back();
		if(l.len==r.len) ans+=l.len*(l.ch!=r.ch);
		else if(l.len<r.len){
			ans+=l.len*(l.ch!=r.ch);
			r.len-=l.len;
			q.push_back(r);
		}
		else{
			ans+=r.len*(l.ch!=r.ch);
			l.len-=r.len;
			q.push_front(l);
		}
	}
	cout << ans;
	return 0;
}

