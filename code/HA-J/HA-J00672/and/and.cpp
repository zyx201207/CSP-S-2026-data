#include<bits/stdc++.h>
#define endl '\n'
#define debug cout << "qwq" << endl;
using namespace std;

const int N = 2e5 + 10;
int n, m, res;
bool mk[N];
int a[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 30; i >= 0; i --){
		int cnt = 0;
		for(int j = 1; j <= n; j ++){
			if(mk[j]) continue;
			if(a[j] & (1 << i)) cnt ++;
		}
		//如果>=m个，则这一位可以选，而且接下来的位置只能从这些数里面选了。 
		if(cnt >= m){
			res |= (1 << i);
			for(int j = 1; j <= n; j ++){
				if((a[j] & (1 << i)) == 0) mk[j] = true;
			} 
		}
		//否则，这一位不做任何限制，且不产生任何贡献。 
	}
	
	cout << res << endl;

	return 0;
}
/*
9：31 
挂了一个B的对拍 
C题似乎是好做的
为什么感觉做法比B题还要显然（？） 
注意到显然更高位取1比剩下位都取1还要优，贪心的从高到低考虑每一位
扫描所有n个数，看哪一个当前位为1
如果>=m个，则一定会从当前位为1的里面选。
把这些数记起来，用于下一位的循环，同时把答案的这一位设成1
否则，当前这一位显然取不到1，则取0，同时把所有数传到下一次的循环
时间复杂度 O(n log sum)，可以通过 
上个厕所。哦哦怎么有人去厕所了啊，去不了了。 
懒得优化了，反正可以通过，那就直接标记一下这个数能不能在这一次循环用算了 
9:46
这不对吧，怎么过大样例了，再挂个拍子吧。不对啊，我要给下午攒RP啊。 
*/
