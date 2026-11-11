#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool f = 1;//记录是否满足条件B:i (1 ≤ i ≤ n),均有 a i = i − 1。
struct stu{
	ll x;//十进制的值
	string s;//二进制形式
}a[400000];
ll n, m;
bool cmp(stu x,stu y){
	return x.x < y.x;
}

string erjinzhi(ll x){//转二进制子程序
	string ans = "";
	while(x){//短除法
		if(x % 2 == 1) ans += "1";
		else ans += "0";
		x /= 2;
	}
	//余数倒序排列
	reverse(ans.begin(),ans.end());
	return ans;
}
void part(){//部分分
	for(ll i = 1;i <= n;++i){
		a[i].s = erjinzhi(a[i].x);//将a数组中的所有数字转成二进制,并放入s数组中存储
	}
	if(!f) sort(a + 1,a + n + 1,cmp);//按十进制排列(不满足条件B);
	ll maxn = -100;//记录所有&值中间的最大值,初始化为极小值(0 <= ai);
	for(ll i = 1;i <= n - m + 1;++i){//枚举起始位置
		ll zhi = a[i].x;//记录&的值(任何数&自己还得自己)
		for(ll j = i;j <= i + m - 1;++j){//枚举以下标i为起始位置的后面的m个数
			zhi = zhi & a[j].x;//&计算
		}maxn = max(maxn, zhi);//取最大值
	}
	cout << maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1;i <= n;++i){
		cin >> a[i].x;
		if(a[i].x != i - 1) f=0;//判断是否符合B,不符合,标记为0
	}
	part();
	return 0;
}
