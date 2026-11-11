#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005]; 
bool in[300005];
int cnt[300005];
stack<int> card;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = n;i >= 1;i--){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		if(!in[a[i]]) {
			card.push(a[i]);
			if(i != n) in[a[i]] = 1;
		}else{
			while(card.top() != a[i])
			{
				in[card.top()] = 0;
				card.pop();
			}
		}
		for(int i = 1;i <= m;i++) if(in[i]) cnt[i]++;
	}for (int i = 1;i <= m;i++) cout << cnt[i] << ' ';
}
