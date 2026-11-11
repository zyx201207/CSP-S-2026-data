#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;
#define int ll
const int M = 3e5 + 10;
//-static
int n , m;
//            预备役 
queue<int> big_cnt_card;

int cnt[M] , stay[M];
signed main(){
	freopen( "card.in" , "r" , stdin );
	freopen( "card.out" , "w" , stdout );
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ ){
		int c;
		cin >> c;
		big_cnt_card.push(c);
	}
	for( int i = 1 ; i <= n ; i++ ){
		queue<int> cnt_card = big_cnt_card;
		big_cnt_card.pop();
		//           桌上的    
		stack<int> card_have;
		while( !cnt_card.empty() ){
			int c = cnt_card.front();
			cnt_card.pop();
			//场上有关于本点数的牌
			if( cnt[c] >= 1 ){
				while( !card_have.empty() ){
					int t = card_have.top();
					card_have.pop();
					
					if( c == t ) break;
					cnt[t]--;
				}
				cnt[c]--;
			}
			cnt[c]++;
			card_have.push(c);
		}
		memset( cnt , 0 , sizeof(cnt) );
		stack<int> tmp = card_have;
		//cout << "tmp:";
		while( !tmp.empty() ){
			int t = tmp.top();
			//cout << t << " ";
			stay[t]++;
			tmp.pop();
		}
		//cout << "\n";
	}
		
	for( int i = 1 ; i <= m ; i++ ) cout << stay[i] << " ";
	return 0;
}
