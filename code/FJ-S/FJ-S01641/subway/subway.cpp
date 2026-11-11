#include<iostream>
using namespace std;
struct Edge{
	int w,l[25],t[45];
}e[500005];
int c,n,m,d,q;
long long tm;
void search(int x,int y){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>e[i].w;
	}
	int t,a;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[a].l[i]=i;
			e[a].t[e[a].l[i]]=t; 
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		tm+=e[x].w+e[y].w;
		int sum=-1;
		for(int j=1;j<=20;j++){
			if(e[x].l[j]==e[y].l[j]){
				sum=max(sum,e[x].t[e[x].l[j]]+e[y].t[e[y].l[j]]);
			}
		}
		tm+=sum; 
		cout<<tm<<'\n';
		tm=0;
	}
	return 0;
}
