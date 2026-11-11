#include<bits/stdc++.h>
using namespace std;
int t[1005][1005];
int c,n,m,d,q,w[500005];
bool h=false,hx[1005];
long long ans=0;
void f(int x,int j,long long s){
	if(x==j){
		s+=w[j];
		if(!h){
			h=true;
			ans=s;
		}else{
			ans=min(ans,s);
		}
		return ;
	}
	hx[x]=true;
	for(int i=1;i<=1000;i++){
		if(t[x][i]!=0&&!hx[i]){
			f(i,j,s+t[x][i]);
		}
	}
	hx[x]=false;
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k==1){
			int a,b;
			cin>>a>>b;
			continue;
		}
		if(k==2){	
			int xa,ya,xb,yb;
			cin>>xa>>ya>>xb>>yb;
			t[xa][xb]=ya+yb;
			t[xb][xa]=ya+yb;
			continue;
		}
	}
	for(int i=1;i<=q;i++){
		h=false;
		ans=0;
		int a,b;
		cin>>a>>b;
		f(a,b,w[a]);
		cout<<ans<<endl;
	}
}
