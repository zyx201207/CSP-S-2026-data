#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans;
struct Node{
	int next,come,go,start;
}w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i].start);
	for(int i=1;i<=n;i++){
		int k,l,r,w1,w2;
		scanf("%d%d%d%d%d",&k,&l,&w1,&r,&w2);
		w[l].next=r;
		w[l].come=w1;
		w[r].go=w2;
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l<r){
			ans=w[l].start+w[l].come+w[r].go+w[r].start;
			for(int i=w[l].next;i!=r;i=w[i].next)ans+=w[i].go+w[i].come;
		}else{
			ans=w[l].start+w[l].go+w[r].come+w[r].start;
			for(int i=w[r].next;i!=l;i=w[i].next)ans+=w[i].go+w[i].come;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
