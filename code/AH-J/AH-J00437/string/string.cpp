#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll num;
	char c;
};
ll n , cnt;
deque<node> dq;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(ll i = 1 ; i <= n ; i++){
		node x;
		cin >> x.num >> x.c;
		dq.push_back(x);
	}
	while(dq.size() != 1){
		node st = dq.front(); dq.pop_front();
		node ed = dq.back(); dq.pop_back();
		if(st.c != ed.c){
			if(st.num < ed.num){
				cnt += st.num;
				node x;
				x.num = ed.num - st.num , x.c = ed.c;
				dq.push_back(x);
			} 
			else if(st.num > ed.num){
				cnt += ed.num;
				node x;
				x.num = st.num - ed.num , x.c = st.c;
				dq.push_front(x);
			} 
			else cnt += st.num;
		}else{
			if(st.num < ed.num){
				node x;
				x.num = ed.num - st.num , x.c = ed.c;
				dq.push_back(x);
			} 
			else if(st.num > ed.num){
				node x;
				x.num = st.num - ed.num , x.c = st.c;
				dq.push_front(x);
			}
		}
	}
	cout << cnt;
	return 0;
}//for AC solve100p
