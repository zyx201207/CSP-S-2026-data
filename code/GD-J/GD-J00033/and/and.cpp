#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],ans;
bool cmp(int a,int b){return a>b;}
vector<int> v,tmp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)v.push_back(a[i]);
    for(int i=30;i>=0;i--){
    	tmp.clear();
    	int cnt=0;
    	for(auto tx:v){
    		if(tx&(1<<i)){
    			tmp.push_back(tx);
    			cnt++;
			}
		}
    	if(cnt>=m){
    		ans+=(1<<i);
    		v.clear();
    		for(auto tx:tmp)v.push_back(tx);
		}
	}
	cout<<ans<<endl;
	return 0;
}
//服了怎么是这种位运算的恶心题目啊 
//有点思路，但是还没做过这种题，没事，实在不行骗分
//通过位运算的性质可以知道，你选m个数，如果某一位是1
//必须这一位全部也都是1 
//这样乱搞能过性质B???
//行了：对于性质A、B:直接排序求最大的m个值
//感觉是贪心。
//如果我有一个高位，肯定比若干个低位加起来要更优
//所以我们逐一满足，先排个序再说 
//对于每一位，我们都可以枚举一遍
//总位数不多，复杂度应该是O(n)的 
//5 3
//6 3 9 4 5 
//不可能存在就直接跳过，只要存在就肯定优先选他 
//nicer!!!大样例过了，我的心砰砰跳，难道真的能拿到300+一等奖不用退役了？ 
//10：05通过T3全部大样例，最顺利一次 
//但是有又感觉有点慌，这大样例有点水 
//ltc love xju 我想上迷惑行为榜！！！ 
