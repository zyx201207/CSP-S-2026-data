#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10005],p[10000][10005],cnt[10005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=a[i]%m+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			p[i][j]=a[j];
			for(int o=0;o<sizeof(p);o++){
				if(a[j]==p[i][o]){
					for(int u=sizeof(p);u>o;u--){
						p[i][u]=0;
					}
				}
			}
		}
		for(int y=0;y<n;y++){
			cnt[p[i][y]]++;
		}
	}
for(int i=0;i<sizeof(cnt);i++){
	cout<<cnt[i];
}
	return 0;
} 
