#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector <ll> a, diff;
//啊啊啊我真服了本来半个小时切掉T1的，结果自己构造数据的时候把题意理解错了，用错误的数据把我的正解“hack”掉了，多花了我1个多小时 T v T
//我还发烧了QAQ好难受，打暴力都没思路 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//  remember to freopen!!!!!!!!!!!!!!!
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	a.resize(n);
	diff.resize(n-1);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	
	sort(a.begin(), a.end()); //sheng xv
	for(int i = 0; i < n-1; ++i){
		diff[i] = a[i+1]-a[i];
	}

	int maxlen = 0;
	ll sum = 0, prev = 0;
	deque <int> q; //cun xia biao
	
	{
		
	for(int i = 0; i < n-1; ++i){
		while(!q.empty() && sum + diff[i]*((int)q.size()+1) > m){
			sum -= prev;
			prev -= diff[q.back()];
			q.pop_back();
		}
		
		if(sum + diff[i]*((int)q.size()+1) <= m){
			q.push_front(i);
			sum += diff[i]*((int)q.size());
			prev += diff[i];
			maxlen = max(maxlen, (int)q.size()+1);
		}
		
	}
	
	}
	
	cout << maxlen << '\n';
	
	return 0;
}
/*
5
-10000000000
-19
0
19
10000000000

5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4

8 6
-4 5 9 -2 1 0 3 3

4

5 1
1 2 1 2 1

3

4 7
3 4 5 9

3

*/

