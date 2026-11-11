#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t;
int n,d;
int a[N];
int cnt;
int minstep = 0x3f;
void dfs(int x,int y,int step){
	if(x>=y){
		if(step<minstep){
			cnt = 1;
			minstep = step;
		}
		else if(step == minstep){
			cnt++;
		}
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,step+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(n<=20){//n小于等于10的测试点，暴力 
			int ans = 0;
			cnt = 0;
			minstep = 0x3f;
			for(int i=1;i<=n-2;i++){
				for(int j=i+2;j<=n;j++){
					cnt = 0;
					minstep = 0x3f;
					dfs(i,j,0);
					if(cnt==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			int d = d/(a[2]-a[1]);
			cout<<n - d - 1<<endl;
		}
	}
	return 0;
} 
