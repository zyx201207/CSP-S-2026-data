#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],x[N],ans[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int tot=0;
		for(int p=0;p<=n;p++){
			x[p]=0;
		}
		for(int j=i;j<=n;j++){
			bool f=0,wz;
			for(int k=1;k<=tot;k++){
				if(a[j]==x[k]){
					f=1;
					wz=k;
					break;
				}
			}
			if(f){
				int o=0;
				for(int k=wz;k<=tot;k++){
					x[k]=0;
					o++;
				}
				tot-=o;
			}
			x[tot+1]=a[j];
			tot++;
		}
		for(int q=1;q<=tot;q++){
			ans[x[q]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
