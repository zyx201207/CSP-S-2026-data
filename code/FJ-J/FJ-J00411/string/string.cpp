#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=200005;
ll num[MAXN];
string c[MAXN];
ll type[30];
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		sum+=num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num[i];j++){
			s+=c[i];
		}
	}
	//新建种类判断，字符有多少种，后面for循环按照字符种类进行枚举
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i-1]) type[(int)c[i]]++;
	}
	//前面正确，构造字符串
	//下一步特判，无需更改直接就是回文串（能够拿部分分） 
	string t=s;
	reverse(s.begin(),s.end());
	if(t==s) cout<<0<<endl;
	//else 开始逐步枚举（从小到大试着枚举整个字符串中的每一位，每次枚举都进行翻转，直到能让字符串变成回文串
	//尽量不超时，能过较小部分数据，大数据可能TLE 
	else{
		for(int i=0;i<sum;i++){
			
		}
	}
	return 0;
}
//s.insert()插入字符？ 
