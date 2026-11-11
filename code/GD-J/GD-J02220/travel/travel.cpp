#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1;
const int inf = 0x3f3f3f3f;
signed main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out " , "w" , stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int c1 , id1 , c2 , id2;
	char s1 , s2 ;
	cin >> c1 >> id1 >> s1 >> c2 >> id2 >> s2;
	if(c1 == c2){//同一节车厢
		cout << 1;
	}else{
		cout << 0;
	}
	if(c1 == c2 && id1 == id2){//同一节车厢的同一排
		cout << 1;
	}else{
		cout << 0;
	}
	if(c1 == c2 && id1 == id2 && (s1 >= 'A' && s1 <= 'C' && s2 >= 'A' && s2 <= 'C' || s1 >= 'D' && s1 <= 'F' && s2 >= 'D' && s2 <= 'F')){//同一节车厢的同一排，且位于过道的同一侧
		cout << 1;
	}else{
		cout << 0;
	}
	if(c1 == c2 && id1 == id2 && ((s1 == 'A' && s2 == 'B' || s1 == 'B' && s2 == 'A' || s1 == 'B' && s2 == 'C' || s1 == 'C' && s2 == 'B') || (s1 == 'D' && s2 == 'F' || s1 == 'F' && s2 == 'D'))){//两张车票对应的座位是否相邻
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
} 
