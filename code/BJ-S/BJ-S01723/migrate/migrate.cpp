#include<bits/stdc++.h>
using namespace std;

const int N=2e6;

int tid,t;
int n;
long long m;
long long a[N+5];
int nxt[N+5];

void get_nxt(){
	int p=n;
	for(int i=n;i>=1;--i){
		while(a[p]-a[i]>m){
			--p;
		}
		nxt[i]=p;
	}
	return;
}

int tb[N+5][3];

int qry(int x,int o){
	if(nxt[x]==x){
		return 0;
	}
	if(tb[x][o]!=-1){
		return tb[x][o];
	}
	int rt=0;
	if(o==0){
		if(max(x+1,nxt[x-1]+1)>nxt[x]){
			rt=0;
		}
		else if(max(x+1,nxt[x-1]+1)==nxt[x]){
			rt+=qry(nxt[x],0);
		}
		else{
			rt+=qry(nxt[x],1);
		}
	}
	else if(o==1){
		rt+=(max(nxt[x-1],x)-max(nxt[x-2],x));
		if(max(x+1,nxt[x-2]+1)>nxt[x]){
			rt=0;
		}
		else if(max(x+1,nxt[x-1]+1)>nxt[x]){
			rt+=qry(nxt[x],2);
		}
		else if(max(x+1,nxt[x-1]+1)==nxt[x]){
			rt+=qry(nxt[x],0);
		}
		else{
			rt+=qry(nxt[x],1);
		}
	}
	else{
		rt+=(nxt[x]-max(nxt[x-1],x));
		if(max(x+1,nxt[x-1]+1)>nxt[x]){
			rt=0;
		}
		else{
			rt+=qry(nxt[x],2);
		}
	}
	tb[x][o]=rt;
	return rt;
}

int cal(int x){
	if(x==nxt[x]){
		return 0;
	}
	if(x+1==nxt[x]){
		return qry(nxt[x],0);
	}
	return qry(nxt[x],1);
}

long long solve(){
	long long ans=0;
	get_nxt();
	for(int i=1;i<=n;++i){
		tb[i][0]=-1;
		tb[i][1]=-1;
		tb[i][2]=-1;
	}
	for(int i=1;i<=n;++i){
		ans+=cal(i);
	}
	return ans;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tid>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		cout<<solve()<<'\n';
	}
	return 0;
}//answer 100pts
