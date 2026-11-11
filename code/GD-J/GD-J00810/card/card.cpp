#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],l[1000005],ll[1000005],lll[1000005],ans[1000005],tot=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],l[a[i]]=i,ll[a[i]]++;
	for(int i=1;i<=m;i++){
		if(lll[i])continue;
		int j=l[i],lx=0;
		while(j<=n){
			if(!lll[a[j]])lx+=ll[a[j]]; 
			ans[a[j]]+=lx;
			lll[a[j]]=1;
			j=l[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
