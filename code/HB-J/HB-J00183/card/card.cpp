#include <bits/stdc++.h>
using namespace std;
int bucket[300005] = {0};
int turn[300005] = {0};
int arr[500005] = {0};
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			q.push(arr[j]);
			bucket[arr[j]]++;
			if(bucket[arr[j]] > 1){
				bucket[q.top()]--;q.pop();
				while(q.top() != arr[j]){bucket[q.top()]--;q.pop();}
			}
		}
		for(int i = 1;i <= m;i++){
			turn[i] += (bucket[i] > 0);
			bucket[i] = 0;
		}
	}for(int i = 1;i <= m;i++){
		cout << turn[i] << " ";
	}
	return 0;
}
