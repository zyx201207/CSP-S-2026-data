#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int x=1;
		for(int j=i;j<=n;j++){
			bool f=false;
			int pos=-1;
			for(int k=x-1;k>=1;k--){
				if(b[k]==a[j]){
					f=true;
					pos=k;
				}
			}
			if(f){
				for(int k=x;k>pos;k--){
					b[k]=0;
				}
			}else{
				b[x]=a[j];
				x++;
			}
		}
		for(int j=1;j<=n;j++)cnt[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout << cnt[i] << " ";
	return 0;
}
