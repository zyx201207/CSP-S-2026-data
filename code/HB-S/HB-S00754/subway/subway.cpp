#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],a[501][500001],k,x,y;
int t[501][500001];
/*bool f[500001]={0};
long long ans[500001];
struct lsq{
    int v,nex,di;
}l[1000001];
int cnt,head[1000001];
void add(int x,int y,int z){
    cnt++;
    l[cnt].nex=y;
    l[cnt].v=head[x];
    l[cnt].di=z;
    head[x]=cnt;
}
struct aaa{
    long long cd,xz;
    friend bool operator < (aaa x,aaa y) {
        return x.cd>y.cd;
    }
};
priority_queue<aaa> qq;
void dij(int s,int o){
    memset(ans,20,sizeof(ans));
    memset(f,0,sizeof(f));
    ans[s]=0;
    qq.push({0,s});
    while(!qq.empty()){
        aaa haha=qq.top();
        qq.pop();
        int hh=haha.xz;
        if(f[hh]){
            continue;
        }
        f[hh]=1;
        for(int i=head[hh];i;i=l[i].nex){
            int en=l[i].di;
            if(ans[i]>ans[hh]+en){
                ans[i]=ans[hh]+en;
                qq.push({ans[i],i});
            }
        }
        if(hh==o){
            break;
        }
    }
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][a[i][j]];
            /*add(a,n+i,t);
            add(n+1,a,t);*/
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
//		dij(x,y);
		int ans=w[x]+w[y];
		for(int i=1;i<=n;i++){
            if(a[i][1]==x && a[i][2]==y){
                cout<<ans+t[i][x]+t[i][y]<<endl;
            }
            if(a[i][1]==y && a[i][2]==x){
                cout<<ans+t[i][x]+t[i][y]<<endl;
            }
		}

	}
	return 0;
}
