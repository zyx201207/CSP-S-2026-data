#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	deque<pair<long long, char>> q;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		char ch;
		long long num;
		cin >> num >> ch;
		q.push_back({num, ch});
	}
	long long cnt = 0;
	while(!q.empty()){
//		for(auto check : q){
//			cout << check.first << ' ' << check.second << ' ';//
//		}
		//cout <<"#" << endl ;//
		if(q.size() == 1){
			break;
		}
		if(q.front().second == q.back().second){
			long long num1 = q.front().first;
			long long num2 = q.back().first;
			char ch1 = q.front().second;
			char ch2 = q.back().second;
			//cout << num1 << ' ' << ch1 << ' ' << num2 << ' ' << ch2 << endl;//
			if(num1 == num2){
				q.pop_back();
				q.pop_front();
				continue;
			} 
			else if(num1 > num2){
				q.pop_back();
				q.pop_front();
				q.push_front({(num1 - num2), ch1});
				continue;
			}
			else{
				q.pop_back();
				q.pop_front();
				q.push_back({(num2 - num1), ch2});
				continue;	
			}
		}
		else{
			long long num1 = q.front().first;
			long long num2 = q.back().first;
			char ch1 = q.front().second;
			char ch2 = q.back().second;
			//cout << num1 << ' ' << ch1 << ' ' << num2 << ' ' << ch2 << endl;//
			if(num1 == num2){
				q.pop_back();
				q.pop_front();
				cnt += num1;
				continue;
			} 
			else if(num1 > num2){
				q.pop_back();
				q.pop_front();
				q.push_front({(num1 - num2), ch1});
				cnt += num2;
				continue;
			}
			else{
				q.pop_back();
				q.pop_front();
				q.push_back({(num2 - num1), ch2});
				cnt += num1;
				continue;	
			}
		}
	}
	cout << cnt;
	return 0;
}

