#include<bits/stdc++.h>
using namespace std;

int c,T;
int n,a[5005],d,cnt,mn = 0x3f3f3f3f,ans;
void dfs(int x,int e,int step)
{
	if(x == e){
		if(step < mn){
			mn = step;
			cnt = 1;
		}
		else if(step = mn) cnt++;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x] <= d) dfs(i,e,step+1);
		else break;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		memset(a,0,sizeof(a));
		ans = 0;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt = 0,mn = 0x3f3f3f3f;
				dfs(i,j,0);
				if(cnt == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
