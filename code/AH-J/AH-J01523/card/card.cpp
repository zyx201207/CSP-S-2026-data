#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],ans[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=30000){
		for(int i=1;i<=n;i++){
			memset(t,0,sizeof t);
			for(int k=i;k<=n;k++)t[a[k]]++;
			int j=n;
			while(--j>=i){
				if(t[a[j]]>1)break;
			}
			for(;j<=n;j++)ans[a[j]]++;
			a[i]=0;
			cout<<"\n";
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else for(int i=1;i<=m;i++)cout<<0<<" ";
	return 0;
}
