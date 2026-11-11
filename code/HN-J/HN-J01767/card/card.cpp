#include <bits/stdc++.h>
using namespace std;
#define int long long
int an[1000000+10],bn[1000000+10],cn[1000000+10],dn[1000000+10];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	for(int i=1;i<=n;i++){
		memset(bn,0,sizeof(bn));
		for(int j=i;j<=n;j++){
			if(bn[an[j]]==0){
				bn[an[j]]=1;
				cn[an[j]]++;
			}
			else{
				for(int o=1;o<=j-1;o++){
					if(an[o]==an[j]){
						while(o<=n){
							bn[an[o]]=0;
							o++;
						}
						break;
					}
				}
				for(int o=1;o<=m;o++){
					cn[o]--;
				}
				bn[an[j]]=1;
				cn[an[j]]++;
			}
		}
	}
	cn[m]++;
	for(int i=1;i<=m;i++){
		cout<<cn[i]<<" ";
	}
	return 0;
}
