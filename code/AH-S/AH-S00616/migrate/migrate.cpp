#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int n,d;
int minn = 2000006;
int mp[2000006];
void dfs(int x,int y,int step){
//	cout << x << ' ' << y << " do\n"; 
	if(x == y){
		mp[step] ++;
//		cout << step << endl;
		minn = min(step,minn);
		return;
	}else{
		if(a[x] + d < a[x + 1]){
//			cout << " false\n"; 
//			step =12000006;
//			mp[step] ++;
//			minn = min(step,minn);
			return;
		}
		int i = 1;
		while(a[x] + d >= a[x + i]&&x + i <= y){
//			cout << x + i << ' ' <<y  << step + 1 << endl;
			dfs(x + i,y,step + 1);
			i ++;
		}
		
	}
	return; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t --){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
			for(int j = 3;j < i;j ++){
				if(i - j <= 0)break;
				minn = 2000006;
				for(int k = 1;k <= j;k ++)mp[k] = 0;
//				cout << i - j << "<<" <<i << "\n";
				dfs(i - j,i,0);
//				cout << i - j << ' ' << i << ' ' << mp[minn] << ' ' << minn << endl;
				if(mp[minn] == 2&& minn != 2000006) ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

