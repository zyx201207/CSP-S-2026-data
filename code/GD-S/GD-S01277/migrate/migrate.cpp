#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int a[N],mx=0,mn[N];
int n,d,cnt[2000005]={0};
void dfs(int st,int x,int l){
	if(a[x]==mx) return;
	int i=x+1;
	while(a[i]-a[x]<=d&&a[i]-a[x]>0){
		l+=a[i];
		if(mn[i]>l){
			mn[i]=l;
			cnt[i]=1;
		}
		else{
			cnt[i]++;
		}
		dfs(st,i,l);
		i++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int k=1;k<=t;k++){
		int ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			memset(mn,127,sizeof(mn));
			dfs(i,i,i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
