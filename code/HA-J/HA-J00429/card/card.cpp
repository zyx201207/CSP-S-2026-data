/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dd double
#define pii pair<int,int>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	int f=1;
	ll x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e6+999;
int n,m;
int a[N];
int pos[N];

//l
struct LIAN{
	int to,ne;
}lian[N];
int h[N],lcnt;
int ru[N];
void add(int u,int v){
	lian[++lcnt].to=v,lian[lcnt].ne=h[u],h[u]=lcnt;
	ru[v]++;
}
//io
void input(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
}
//init
int cnt[N];
void init(){
	for(int i=n;i>0;i--){
		if(!pos[a[i]]){
			pos[a[i]]=i;
			if(i<n)add(a[i],a[i+1]);
		}
		cnt[a[i]]++;
	}
}
//solve
void topu(){
	queue<int>q;
	for(int i=1;i<=m;i++){
		if(ru[i]==0)q.push(i);
	}
	while(q.size()){
		int now=q.front();
		q.pop();
		for(int i=h[now];i;i=lian[i].ne){
			int to=lian[i].to;
			cnt[to]+=cnt[now];
			ru[to]--;
			if(ru[to]==0)q.push(to);
		}
	}
	for(int i=1;i<m;i++)cout<<cnt[i]<<' ';
	cout<<cnt[m]<<'\n';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);


	input();
	init();
	topu();
	return 0;
}

