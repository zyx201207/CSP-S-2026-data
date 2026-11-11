#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 2000005
#define M 305
int c,t;
int n,d;
int a[N];
int ans,minn = 10000000,sum;
void dfs(int s,int e,int w){
	if(s == e){
		if(w < minn) minn = w,sum = 1;
		else if(w == minn) sum++;
		return;
	}
	else{
		for(int i = s+1;i <= e;i++){
			if(a[i] - a[s] <= d){
				dfs(i,e,w+1);
			}
			else break;
		}
	}
}
int main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c <= 6){
		while(t--){
			cin >> n >> d;
			for(int i = 1;i <= n;i++) cin >> a[i];
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					dfs(i,j,0);
//					cout << i << " " << j << " " << sum << " " << minn << "\n";
					if(sum == 2 && minn != 1) ans++;
					sum = 0;
					minn = 10000000;
				}
			}
			cout << ans << "\n";
			for(int i = 1;i <= n;i++) a[i] = 0;
			ans = 0;
		}
	}
	if(c == 11 || c == 12){//ÌØÊâÐÔÖÊA
		while(t--){
			cin >> n >> d;
//			for(int i = 1;i <= n;i++) cin >> a[i];
			LL a,b;
			cin >> a >> b;
			LL k = b - a;
			LL c = d / k;
			cout << max(0,int(n-c*2+1)) << "\n";
//			for(int i = 1;i <= n;i++) a[i] = 0;
		}
	}
	
	return 0;
}
