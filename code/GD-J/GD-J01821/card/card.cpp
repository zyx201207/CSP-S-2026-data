#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e5+10;
int n,m,a[N],cnt[M],c[M],ans[M];
bool v[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cnt[a[i-1]]--;
		for(int i=1;i<=m;i++)
			c[i]=cnt[i];
		memset(v,0,sizeof(v));
		int p=i;
		for(int j=i;j<=n;j++)
			if(c[a[j]]>1){
				c[a[j]]--;
				int pos=j+1;
				while(pos<n){
					pos++;
					if(a[pos]==a[j])
						break;
				}
				p=min(n,pos);
				j=pos-1;
			}
		for(int j=p;j<=n;j++)
			if(!v[a[j]]){
				v[a[j]]=1;
				ans[a[j]]++;
			}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
