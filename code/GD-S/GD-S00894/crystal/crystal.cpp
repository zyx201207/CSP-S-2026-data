#include<bits/stdc++.h>
using namespace std;
//freopen(练了好久-J最后初赛只过-S是一件令人啼笑皆非的事情。我要上大赏。）
//foropen(参考 luogu中《如何判断你的前桌是不是猫娘》装了4h，~~可我好像本来就中了1-9~~；渣渣‘是。吴，。迪！。？ )
//	freopen(密码：Oct31==Dec25? 今天是圣诞节ohh ~~你别说还真是（Oct31==Dec25?）~~ 
//froepen(咋有人带糖进来搞别人心态的啊，心态--;拿部分分ing） 
vector<int> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(m == 0){
		cout << 1;
		return 0;
	}
	for(int i = 0;i < n;i ++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	bool f = 0;
	for(int i = 0;i < n;i ++){
		if(a[i] != i + 1){
			f = 1;
			break;
		}
	}
	if(f == 0){
	int yd = 1;
	int cs = 1;
		for(int i = n - 1;i > 0;i --){
			if(m >= yd){
				m -= yd;
				cs ++;
				yd ++;
			}else{
				break;
			}
		}
		cout << cs;
	}else if(f == 1){
		sort(a.begin(),a.end());
		int ma = 0;
		for(int i = 0;i < n;i ++){
			int c = m;
			int ans = 0;
			for(int j = i;j >= 0;j --){
				if(c >= a[i] - a[j]){
					c -= a[i] - a[j];
					ans ++;
				}
			}
			ma = max(ma,ans);
		}
		cout << ma;
	}
}
