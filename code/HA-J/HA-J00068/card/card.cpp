#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],nxt[500005],lst[500005],cnt[500005],p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n-i+1];
	}
	for(int i=1;i<=n;i++){
		nxt[i-1]=i;
		lst[i]=i-1;
		if(p[a[i]]){
			int now=p[a[i]];
			nxt[lst[now]]=i;
			lst[i]=lst[now];
			while(now!=i){
				cnt[a[now]]+=i-p[a[now]];
				p[a[now]]=0;
				now=nxt[now];
			}
			p[a[i]]=i;
		}p[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]+(p[i]?(n-p[i]+1):0)<<' ';
	}
	return 0;
}