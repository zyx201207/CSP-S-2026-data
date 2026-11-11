#include<bits/stdc++.h>
using namespace std;
using ui=unsigned;
int n,m;
ui long long sum[500005];
ui a[500005];
ui nx[500005];
ui temp[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ui i=1;i<=n;i++)cin>>a[i];
	for(ui i=n;i>=1;i--){
		if(temp[a[i]]){
			nx[i]=temp[a[i]];
		}else temp[a[i]]=i;
	}
	for(ui i=1;i<=n;i++){
		for(ui j=i;j<=n;){
			if(nx[j]==0){
				sum[a[j]]++;
				j++;
			}else{
				j=nx[j];
			}
		}
	}
	for(ui i=1;i<=m;i++)cout<<sum[i]<<' ';
	return 0;
}/*
T4第一眼以为是钓小鱼（豆（tang）包belike）
光速写出代码，主要内容如下：
for(int i=1;i<=n;i++){
	if(temp[a[i]]){
		nx[temp[a[i]]]=i;
		temp[a[i]]=0;
	}else temp[a[i]]=i;
}

for(int i=1;i<=n;i++){
	for(int j=i;j<=n;){
		if(nx[j]==0){
			sum[a[j]]++;
			j++;
		}else{
			j=nx[j]+1;
		}
	}
}
然后不对，丝毫没想到读错题了，尝试进行调试，
真找到了一个错误（弄拙成巧），然后更意识不到了。
20min后：
“原来最后一张牌没收上去”
加速改题：
for(int i=1;i<=n;i++){
	if(temp[a[i]]){
		nx[temp[a[i]]]=i;
		temp[a[i]]=i;
	}else temp[a[i]]=i;
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;){
		if(nx[j]==0){
			sum[a[j]]++;
			j++;
		}else{
			j=nx[j];
		}
	}
}
一测，对了，而且过了所有测试点。
20min后，我在读card的题面（似曾相识）：
“13,14测试点m<=2”

手造了上述代码的hack
cout<<500005<<' '<<1<<endl;
for(int i=1;i<=500005;i++)cout<<1<<' ';

（跑了1min）
尝试优化：
一个数x不再找离自己最近的x，而是找最后的x，
中间的数显然会被x"消掉"。
于是所有m较小的测试点都不能把我hack了。

5min后：
const int n=5e5,m=3e5;
cout<<n<<' '<<m<<endl;
for(int i=1;i<=m;i++)cout<<i<<' ';
for(int i=m+1;i<=n;i++)cout<<1<<' ';

不知道如何进行优化（），希望CCF拿舌头（bushi）造数据。
窝要上迷惑行为大赏
不不不，这邮寄比代码还多
I WANT TO AK CSP
while(1)rp++;
窝不要爆0
(认真诈骗ing)
*/
