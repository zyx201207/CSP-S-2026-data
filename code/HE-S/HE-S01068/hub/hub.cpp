#include<bits/stdc++.h>
#define ll long long
#define gc getchar
using namespace std;
int read(){
	int x=0,f=1; char c=gc();
	while(c<'0' or c>'9') { if(c=='-') f=-1; c=gc(); }
	while(c>='0' and c<='9') { x=x*10+c-'0'; c=gc(); }
	return x*f;
}
const ll asd=2e6+90;
ll head[asd]={},nxt[asd<<1]={},to[asd<<1]={},cnt=1;
ll 
void add_edge(ll u,ll v){
	nxt[cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt++;
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}
