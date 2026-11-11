#include<bits/stdc++.h>
using namespace std;
#define int long long
int an[500001],bn[300001],cn[300001],last[300001],maxn;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	for(int i=1;i<=n;i++){
		memset(cn,0,sizeof(cn));
		for(int j=i;j<=n;j++){
			if(cn[an[j]]){
				for(int k=last[an[j]];k<=j;k++) cn[an[k]]=0;
			}
			cn[an[j]]++;
			last[an[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(cn[j]) bn[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<bn[i]<<" ";
	return 0;
}
