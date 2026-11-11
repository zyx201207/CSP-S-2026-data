#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;

int n,m,j,ans,res;
int a[MAXN];

int cnt[31];
bool flag[31][MAXN];
bool can[MAXN];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		for (j=1;j<=30;j++){
			cnt[j]+=(a[i]>>(j-1)&1);
			flag[j][i]=(a[i]>>(j-1)&1);
		}
	}
			
	for (j=30;j>0;j--){
		if (cnt[j]<m) continue;
		
		ans|=(1<<(j-1));
		for (int i=1;i<=n;i++)
			if (!flag[j][i]&&!can[i]){
				can[i]=1;
				for (int k=j-1;k>0;k--)
					if (flag[k][i]) cnt[k]--;
			}
	}
	
	cout<<ans;
	
	return 0;
}
