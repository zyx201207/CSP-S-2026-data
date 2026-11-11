/*不不不这无疑是简单的
还有两个小时孩子们看我ak cspj*/
 
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
int n,m;
int a[MAXN];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans = 0;
	for(int i = 31;i >= 0;i --){
		int cnt = 0;
		
		for(int j = 1;j <= n;j ++){
			if(a[j] < ans) continue;
			if(a[j] & (1 << i)){
				cnt ++;
			} 
		}
		if(cnt >= m) ans += (1 << i);
	}
	cout<<ans;
}
