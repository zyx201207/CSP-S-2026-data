#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],st[22][N],l[N],cnt[N],d[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(cnt[a[i]]>0)
		st[0][cnt[a[i]]]=i;
		cnt[a[i]]=i;
	}
	for(int k=1;k<=20;k++){
		for(int i=1;i<=n;i++){
			st[k][i]=st[k-1][st[k-1][i]];
		}
	}
	int p=-1;
	for(int i=n;i>=1;i--){
		if(st[0][i]){
			p=i;
		}
		l[i]=p;
	}
	d[n]++;
	for(int i=1;i<=n;i++){
		int x=i;
		while(x<n){
			for(int j=20;j>=0;j--){
				if(st[j][x])
				x=st[j][x];
			}
			if(l[x]==-1){
				d[x]++;
				break;
			}else{
				d[x]++;
				x=l[x];
				d[x]--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		ans[a[i]]+=d[i];
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<' ';
	return 0;
}
