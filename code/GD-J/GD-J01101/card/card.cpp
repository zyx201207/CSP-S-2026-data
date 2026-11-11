#include<bits/stdc++.h>
using namespace std;

int a[500010],n,m;
int b[500010];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			b[++cnt]=a[j];
			for(int k=1;k<cnt;k++) if(b[k]==b[cnt]) for(int s=k+1,w=cnt;s<=w;s++,cnt--) b[s]=0;
		}
		for(int k=1;k<=cnt;k++) mp[b[k]]++;
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<' ';
	return 0;
}
