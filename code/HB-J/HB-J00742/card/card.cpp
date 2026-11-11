#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],b[M];
int ans[M];
int v[N],cnt;
bool ok=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) ok=0;
		b[a[i]]++;
	}
	if(ok){
		for(int i=1;i<=m;i++){
			b[i]=b[i-1]+b[i];
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(v,0,sizeof v);
		int j=n;
		while(j>=i){
			if(!cnt){
				v[cnt++]=a[j];
				j--;continue;
			}
			int x=lower_bound(v+1,v+cnt+1,a[j])-v;
			if(v[x]==a[j]) cnt-=x;
			else v[cnt++]=a[j];
			j--;
		}
		for(int w=0;w<cnt;w++){
			ans[v[w]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
