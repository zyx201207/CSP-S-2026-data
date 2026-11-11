#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,m,a[500005],b[300005],ans;
int awa[300005],r,qwq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(ans<m && qwq<n){
		qwq++;
		for(int i=qwq;i<=n;i++)
			if(mp[a[i]]==0){
				r++;
				mp[a[i]]=r;
				awa[r]=a[i];
			}
			else{
				for(int j=mp[a[i]]+1;j<=r;j++)
					mp[awa[j]]=0;
				r=mp[a[i]];
			}
		for(int i=1;i<=m;i++)
			if(mp[i]!=0 && b[i]==0) b[i]=qwq,ans++;
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
