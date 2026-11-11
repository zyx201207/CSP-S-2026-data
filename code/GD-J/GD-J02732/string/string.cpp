#include <bits/stdc++.h>
using namespace std;
struct chuan{
	string le;
	int ti;
};
deque <chuan> q;
long long ans = 0;
void check(){
	if(q.size()<=1){
		return ;
	}
	while(q.size()>1){
		chuan now = q.front();
		chuan now1 = q.back();
		if(now.le == now1.le){
			if(now.ti> now1.ti){
				q[0].ti-=now1.ti;
				q.pop_back();
			}else{
				q.pop_front();
				q[q.size()-1].ti-=now.ti;
			}
		}else{
			if(now.ti>now1.ti){
				ans+=now1.ti;
				q[0].ti-=now1.ti;
				q.pop_back();
			}else{
				ans+=now.ti;
				q.pop_front();
				q[q.size()-1].ti-=now.ti;
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		string y;
		cin >> x >> y;
		q.push_back({y,x});
	} 
	check();
	cout << ans << endl;
	return 0;
}
