#include<bits/stdc++.h>
using namespace std;
//怎么这么喜欢考拆位啊
//考虑对每个数二进制分解然后从高位到低位枚举，如果这一位能选出m个该位为1的那就选
const int N=2e5+5;
bool bit[N][31];
int n,m,a[N],cnt[31]; 
bool f[N];
//简单题 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			bit[i][j]=((a[i]>>j)&1);
			cnt[j]+=bit[i][j];
		}
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(f[j])continue;
				if(!bit[j][i]){
					f[j]=true;
					for(int k=0;k<=30;k++)cnt[k]-=bit[j][k];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
