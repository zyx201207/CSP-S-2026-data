#include<bits/stdc++.h>
using namespace std;
int n,m,s[300005],x[300005],num;
int last[300006],c[300005];
int cf[300005],qzh[300005];
struct node{
	int l,r,w;
}p[300005];
int cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> x[i];
		last[x[i]]=max(last[x[i]],i);
	}
	for(int i=1;i<=n;++i){
		if(s[x[i]]){
			p[++num].l=s[x[i]];
			p[num].r=i;
			p[num].w=s[x[i]];
		}
		s[x[i]]=i;
	}
	sort(p+1,p+num+1,cmp);
	for(int i=1,x;i<=num;++i){
		x=1;
		while(p[i].r>p[i+x].l&&i+x<=num){
			p[i+x].w-=p[i].w;
			x++;
		}
	}
	for(int i=1;i<=n;++i){
		c[i]=i;
	}
	for(int i=1;i<=num;++i){
		cf[p[i].l]-=p[i].w;
		cf[p[i].r]+=p[i].w;
	}
	for(int i=1;i<=n;++i){
		qzh[i]=qzh[i-1]+cf[i];
	}
	for(int i=1;i<=n;++i){
		c[i]+=qzh[i];
	}
	for(int i=1;i<=m;++i){
		cout << c[last[i]] << ' ';
	}
	return 0;
}

