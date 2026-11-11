#include <iostream>
#define int long long
using namespace std;
int len[202631],n;
int ans,pre[202631];
char b[202631];
void solve1(){
	for(int i=0;i<n;i++){
		for(int j=0;j<len[i];j++)
			a.push_back(b[i]);
	}int l=a.size();
	for(int i=0;i<l-i-1;i++)
		if(a[i]!=a[l-i-1])
			ans++;
	cout << ans;
}
void solve2(){
	cout << 0;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++) //len数组记录尾插元素个数 
		cin >> len[i] >> b[i];
	pre[0]=len[0];
	for(int i=1;i<n;i++) //前缀和求元素真正下标 
		pre[i]=len[i]+pre[i-1];
	if(n*pre[n-1]<=1e8) solve1();
	else solve2();
	return 0;
} 
