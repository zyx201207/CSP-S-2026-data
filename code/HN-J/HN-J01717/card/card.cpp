#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500009]={},ans[500009]={},num;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		queue<long long> t;
		queue<long long> q;
		bool v[500009]={};
		for(int j = i;j <= n;j++){
			q.push(a[j]);
		}
		while(!q.empty()){
			for(int j = 1;j <= t.size();j++){
				if(t.front() == q.front()){
					num = t.size();
					for(int l = j;l <= num;l++){
						t.pop();
					}
					break;
				}else{
					t.push(t.front());
					t.pop(); 					
				}

			}
			t.push(q.front());
			q.pop();
		}
		for(int j = 1;j <= t.size();j++){
			if(v[t.front()] == false){
				ans[t.front()]++;
				v[t.front()] = true;
			}
			t.push(t.front());
			t.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
} 
