#include <bits/stdc++.h>
using namespace std;

/*
1 两张车票对应的座位是否在同一节车厢；
cr == cx ?

2 两张车票对应的座位是否在同一节车厢的同一排；
cr == cx && sr[0] == sx[0] && sr[1] == sx[1]

3 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
同上
case1 sr[2] == D -> sr[2] == F
case2 sr[2] == F -> sr[2] == D
case3 sr[2] != D -> sr[2] != D && sr[2] != F

4 两张车票对应的座位是否相邻。 CD不相邻 
case1 sr[2] == A -> sx[2] == B
case2 sr[2] == B -> sx[2] == A || C
case3 sr[2] == C -> sx[2] == B
case4 sr[2] == D -> sx[2] == F
case5 sr[2] == E -> sx[2] == D
*/

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string cr, sr, cx, sx;
	//R车厢号 座位号 
	cin >> cr >> sr >> cx >> sx;
	string ans = "0000";
	//1
	ans[0] = (cr == cx ? '1' : '0');
	//2
	if(cr == cx && sr[0] == sx[0] && sr[1] == sx[1])
		ans[1] = '1';
	//3
	//case1 sr[2] == D -> sr[2] == F
	//case2 sr[2] == F -> sr[2] == D
	//case3 sr[2] != D -> sr[2] != D && sr[2] != F
	if(ans[1] == '1'){
		if(sr[2] == 'D' && sx[2] == 'F')
			ans[2] = '1';
		if(sr[2] == 'F' && sx[2] == 'D')
			ans[2] = '1';
		if(sr[2] != 'D' && sx[2] != 'D' && sx[2] != 'F')
			ans[2] = '1';
	}
	//4
	if(ans[2] == '1'){
		//case1
		if(sr[2] == 'A' && sx[2] == 'B') ans[3] = '1';
		//case2
		if(sr[2] == 'B'){
			if(sx[2] == 'C' || sx[2] == 'A')
				ans[3] = '1';
		}
		//case3
		if(sr[2] == 'C' && sx[2] == 'B') ans[3] = '1';
		//case4
		if(sr[2] == 'D' && sx[2] == 'F') ans[3] = '1';
		//case5
		if(sr[2] == 'F' && sx[2] == 'D') ans[3] = '1';
	}
	
	cout << ans << endl;
	return 0;
}
