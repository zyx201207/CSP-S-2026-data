#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m;
int a[500005],ans[500005];
int pos_last[500005],nxt[500005];
int sum[500005],sum_a;
int t[500005];
int step;
void f(int x,int val){
	if(x>sum_a) return;
	if(a[nxt[x]]!=a[x]) ans[a[x]]+=val;
	else step=1;
	f(nxt[x],val);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		if(t[i]!=t[i-1]){
			a[++sum_a]=t[i];
			sum[sum_a]=1;
		}
		else{
			sum[sum_a]++;
		}
	}
	for(int i=1;i<=sum_a;i++) nxt[i]=i+1;
	for(int i=1;i<=sum_a;i++){
		if(pos_last[a[i]]){
			nxt[pos_last[a[i]]]=i;
		}
		pos_last[a[i]]=i;
	}
	for(int start=1;start<=sum_a;start++){
		step=0;
		f(start,sum[start]);
		if(step==0){
			int all=0;
			for(int j=start+1;j<=sum_a;j++){
				all+=sum[j];
				ans[a[j]]+=all;
			}
			break;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
