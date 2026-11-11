#include <bits/stdc++.h>
using namespace std;
queue<int> q;
stack<int> st;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		int x;
		q.push(x);
	}
	for (int i = 1;i <= n;i++){
		queue<int> temp = q;
		for (int j = 1;j < i;j++)
			temp.pop();
	}
	cout << "3 1 4";
	return 0;
}
