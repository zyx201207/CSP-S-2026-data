#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5+8;
const int MAXM=3e5+8;
int n,m,b[MAXN],sum[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> b[i]; 
	}
	for (int i=1;i<=n;i++){
		int cnt[MAXM]={},a[MAXN];
		for (int j=i;j<=n;j++){
			a[j]=b[j];
		}
		for (int j=i;j<=n;j++){
			cnt[a[j]]++;
			if (cnt[a[j]]>1){
				int k=j,lll=a[j];
				while (1){
					a[k--]=-1;
					if (a[k]==lll)break;
				}
			}
		}
		memset(cnt,sizeof cnt,0);
		for (int j=i;j<=n;j++){
			cnt[a[j]]++;
		}
		for (int j=1;j<=m;j++){
			if (cnt[j])sum[j]++;
		}
	}
	for (int j=1;j<=m;j++){
		cout << sum[j] << " ";
	}
	
	return 0;
}
