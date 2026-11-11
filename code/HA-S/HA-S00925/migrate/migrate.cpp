#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
inline int readint(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline long long a_bs(long long a){
	return a>=0?a:-a;
}
int n,d,ans;
long long x[5010];
int head,zans;
void dis(int u,int v){
	queue<pair<int,int> >q;
	q.push(make_pair(u,0));
	while(!q.empty()){
		pair<int,int>dd=q.front();q.pop();
		if(zans<dd.second){break;}
		if(dd.first==v){head++;zans=dd.second;continue;}
		int nu=dd.first;
		while((++nu)<=v&&(a_bs(x[nu]-x[dd.first])<=(long long)d)){q.push(make_pair(nu,dd.second+1));}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c=readint();
	t=readint();
	while(t--){
		n=readint();
		d=readint();
		for(int i=1;i<=n;i++){x[i]=readint();}
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				head=0,zans=1e9+7;
				dis(u,v);
				if(head==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
