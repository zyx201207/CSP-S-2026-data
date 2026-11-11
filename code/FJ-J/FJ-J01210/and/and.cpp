#include<bits/stdc++.h>
using namespace std;
long long n,m,c[200005],f,d,mmax,e,r,ans;
struct node{
	long long sz,ds;
};
node a[200005];
void dfs(int x,int y,long long z)
{
	if(y==m){
		ans=max(ans,z);
	}else{
		if(x==0) z=LLONG_MAX;
		for(int i=x+1;i<=f;i++){
			dfs(i,y+1,z&a[i].sz);
		}
	}
	
}
bool cmp(node x,node y)
{
	if((x.ds>y.ds)||(x.ds==y.ds)) return 0;
	else return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].sz;
		if(i==1) d=a[i].sz;
		else d=d&a[i].sz;
		mmax=max(mmax,a[i].sz);
	}
	if(m==n) cout<<d<<endl;
	else if(m==1) cout<<mmax<<endl;
	else if(m==2){
		mmax=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				mmax=max(mmax,a[i].sz&a[j].sz);	
			}
		}
		cout<<mmax<<endl;
	}else{
		mmax=0;
		for(int i=1;i<=n;i++){
			e=a[i].sz;
			while(e>0){
				a[i].ds++;
				e/=2;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].ds>=a[m].ds) c[++f]=a[i].sz;
		}
		if(f==m){
			r=c[1];
			for(int i=2;i<=m;i++) r=r&c[i];
			cout<<r<<endl;
		}else{
			dfs(0,0,0);
			cout<<ans<<endl;
		}
	}
}