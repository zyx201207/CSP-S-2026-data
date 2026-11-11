#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
int a[N],nxt[N],h[M],sum[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ct=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!h[a[i]]) h[a[i]]=i;
		else{
			ct=max(ct,h[a[i]]);
			nxt[h[a[i]]]=i,h[a[i]]=i;
		} 
	}
	for(int i=1;i<=n;i++){
		if(i>ct){
			for(int j=i;j<=n;j++){
				sum[a[j]]+=(j-i+1);
			}
			break;
		}
		for(int j=i;j<=n;){
			if(j==h[a[j]]) sum[a[j]]++,j++;
			else j=nxt[j];
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",sum[i]);
	return 0;
} 
