#include <bits/stdc++.h>
#include <deque>
using namespace std;

const int maxn = 5e5 + 5;
long long a[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout); 
	long long n,m;
	cin >> n >> m;
	
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1 , a + n + 1);
	
	long long ans = 0;
	long long curm = 0;
	long long element = 0;
	deque<long long> deq; 
	for(int i = 1;i<=n;i++){
		if(!deq.empty() && curm + element * (a[i] - deq.back()) <= m){
			curm += element * (a[i] - deq.back());
			element ++;
			ans = max(ans , element);
			deq.push_back(a[i]);
			continue;
		}
		if(deq.empty()){
			deq.push_back(a[i]);
			element ++;
			ans = max(ans , element);
			continue;
		}
		curm += element * (a[i] - deq.back());
		element ++;
		while(!deq.empty() && curm > m){
			curm -= (a[i]-deq.front());
			deq.pop_front();
			element --;
		} 
		deq.push_back(a[i]);
		ans = max(ans , element);
	}
	cout << ans << endl;
	
	return 0;
}
