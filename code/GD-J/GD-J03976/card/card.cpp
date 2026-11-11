#include<bits/stdc++.h>
using namespace std;

int a[5000005],ans[3000005],x[3000005],s[3000004];

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int k = 0;
		memset(x,0,sizeof(x));
		for(int j=i,r=1;j<=n;r++,j++){
			x[a[j]]++;
			s[r] = a[j];
			if(x[a[j]] == 2) {
				for(int f=r-1;f>=1;f--){
					x[s[f]]=0;
					if(s[f] == a[j]){
						break;
					}
				}
				x[a[j]]++;
			}
			k = max(k,a[j]);
		}
		for(int i=1;i<=k;i++)
			if(x[i]) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
