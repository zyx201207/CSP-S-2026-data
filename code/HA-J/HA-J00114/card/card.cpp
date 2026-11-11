#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],nex[N],n,m,pos[N],num[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(pos,0,sizeof(pos));
	for(int i=n;i>=1;i--){
		nex[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(nex[nex[i]])
			nex[i]=nex[nex[i]];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nex[j]){
				j=nex[j]-1;
				continue;
			}
			num[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	return 0;
}
