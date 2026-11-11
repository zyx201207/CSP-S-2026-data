#include<bits/stdc++.h>
using namespace std;
int val[500010],nxt[500010],pre[500010],tail;
int n,m,a[500010],ans[300010];
bool ch[300010];
void push(int x,int id){
	int in=-1;
	for(int i=nxt[0];i!=-1;i=nxt[i]){
		if(val[i]==x){
			in=i;
			break;
		}
	}
	val[id]=x;
	pre[id]=tail;
	nxt[tail]=id;
	tail=id;
	if(in!=-1){
		nxt[pre[in]]=id;
		pre[id]=pre[in];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=0;
		memset(nxt,-1,sizeof(nxt));
		memset(pre,-1,sizeof(pre));
		nxt[0]=1;
		val[1]=a[i-1];
		pre[1]=0;
		tail=1;
		for(int j=i;j<n;j++){
			push(a[j],j-i+2);
		}
		memset(ch,0,sizeof(ch));
		for(int i=nxt[0];i!=-1;i=nxt[i]){
			if(ch[val[i]]) continue;
			ans[val[i]]++;
			ch[val[i]]=1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
