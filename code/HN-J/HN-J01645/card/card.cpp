#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int an[N],bn[N],cn[N],dn[N];
signed main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>an[i];
	for(int i=1;i<=n;i++){
		memset(bn,0,sizeof(bn));
		memset(cn,0,sizeof(cn));
		int len=0;
		for(int j=i;j<=n;j++){
			if(cn[an[j]]){
				for(int k=cn[an[j]]+1;k<=len;k++)bn[k]=0;
				len=cn[an[j]];
			}else cn[an[j]]=++len,bn[len]=an[j];
		}
		for(int j=1;j<=len;j++)if(bn[j])dn[bn[j]]++;
	} 
	for(int i=1;i<=m;i++)cout<<dn[i]<<" ";
	return 0;
}

