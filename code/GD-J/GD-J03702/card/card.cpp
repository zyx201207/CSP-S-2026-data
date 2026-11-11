#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005],tp[500005],v[300005],cur=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(tp,0,sizeof tp);
		memset(v,0,sizeof v);
		cur=0;
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				for(int k=v[a[j]];k<=cur;k++){
					tp[k]=0;
				}
				cur=v[a[j]]-1;
			}
			tp[++cur]=a[j];
			v[a[j]]=cur;
		}
		for(int j=1;j<=cur;j++){
			ans[tp[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

