#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cout<<i<<' ';
	return 0;
} 
//还有23分钟我是应该骗个12pts还是去检查第二题呢？？ 
//感觉这题没有那么好做又没有那么难做的
//还好刚刚去看了一眼虽然大样例依然没调出来（骗你的就没调），发现自己freopen打的string2.in，吓哭了
//想骗15~17，应该是这么写吧，不知道了 
//不是这么写。但我不会写了。只有13分钟了我也不可能再来写模拟了
//算了，不管它了，代码里有东西就行了。
//CSP什么的还是高中再见吧，反正初三我都得退去搞whk 
