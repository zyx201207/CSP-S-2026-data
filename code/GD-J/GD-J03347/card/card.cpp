#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int f[n+5]; //f[i]表示当前第i张牌是否在 
	int p[n+5]; //牌面 
	for(int i=1;i<=n;i++){
		int l=0; //l表示当前牌桌上还有多少张牌 
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				l++,f[a[j]]=l;
			}
			else {
				for(int k=i+f[a[j]];k<=i+l-1;k++)
					f[a[k]]=0;
				l=f[a[j]];
			}
		}
		for(int j=1;j<=n;j++){
			if(f[a[j]]>0)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
