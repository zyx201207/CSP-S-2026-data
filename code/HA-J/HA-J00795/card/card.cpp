#include<bits/stdc++.h>
using namespace std;
int c[500005],cnt[300005];
int c1[500005],tp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=tp;k++){
				if(c[j]==c1[k]){
					tp=k-1;
					break;
				}
			}
			c1[++tp]=c[j];
		}
		for(int j=1;j<=tp;j++){
			cnt[c1[j]]++;
		}
		tp=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
