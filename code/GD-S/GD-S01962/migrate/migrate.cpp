#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int res = 0,l = 1;char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-')l = -1;
		ch = getchar();
	}
	while(isdigit(ch))res = res * 10 - '0' + ch,ch = getchar();
	return res * l;
}
const int N = 2e6 + 10;
int n,m,a[N],ncn,times,ans;
void dfs(int st,int ed,int nw,int cnt){
	if(cnt > ncn)return;
	if(nw == ed){
		if(ncn > cnt){
			ncn = cnt;
			times = 1;
		}
		else if(cnt == ncn)times++;
	}
	if(a[nw] + m >= a[ed])dfs(st,ed,ed,cnt + 1);
	else{
		for(int i = nw + 1;i <= ed && a[i] - a[nw] <= m;i++)dfs(st,ed,i,cnt + 1);
	}
}
void solve(){
	n = read() , m = read() , ans = 0;
	for(int i = 1;i <= n;i++)a[i] = read();
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			ncn = n,times = 0;
			dfs(i,j,i,0);
			if(times == 2)ans++;
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read(),T = read();
	while(T--) solve();
	return 0;
} 
/*
等到黑夜翻篇之后
会是新的白昼
等到海啸退去之后
只是潮起潮落
别到最后你才发觉
心里头的野兽
还没到最后就已经罢休
心脏没有那么脆弱
总还会有执着
人生不会只有收获
总难免有伤口
不要害怕生命中
不完美的角落
阳光在每个裂缝中散落 
*/
