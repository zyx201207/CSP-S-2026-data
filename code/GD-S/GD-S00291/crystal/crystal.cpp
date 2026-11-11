#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
struct node{
	int id,num;
};
int n,m,now,ans,cnt,cha;
int c[N];
node a[N];
int b[N];
bool flag;
map<int, int> mp;
bool cmp(node x, node y){
	return x.id < y.id;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++){
		int t;
		scanf("%lld",&c[i]);
		if(mp[c[i]] == 0){
			mp[c[i]] = ++cnt;
			a[cnt].id = c[i];
		}
		a[mp[c[i]]].num++;
	}
	sort(c + 1, c + 1 + n);
	sort(a + 1, a + 1 + cnt, cmp);
	cha = c[2] - c[1];
	for(int i = 3; i <= n; i++){
		if(c[i] - c[i - 1] != cha){
			flag = true;
			break;
		}
	}
	if(flag == false){
		ans = n;
		for(int i = 2; i <= n; i++){
			m = m - cha * (i - 1);
			if(m < 0){
				m = m + cha * (i - 1);
				ans = max(i - 1, m / cha + 1);
				break;
			}
		}
		printf("%lld",ans);
		return 0;
	}//*/
	for(int i = 2; i <= cnt; i++){
		a[i].num += a[i - 1].num;
		b[i] = b[i - 1] + (a[i].id - a[i - 1].id) * a[i - 1].num;
	}
	b[cnt + 1] = 1e18;
	a[cnt + 1].num = a[cnt].num;
	for(int i = 0, j = 1; j <= cnt; i++){
		while(b[j] - b[i] <= m && j <= cnt){
			j++;
		}
		ans = max(ans, a[j].num - a[i].num - 1);
	}//*/
	printf("%lld",ans);
	return 0;
}
