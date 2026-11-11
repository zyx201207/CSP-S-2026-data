#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m;
ll d,q;
ll w[500005];
struct plan{
	ll x;
	ll y;
}p[100005];
ll a[505][100005];
ll t[505][100005];
ll k[100005];
ll ans;
bool flag=false;
void dfs(int i,int j,int x){
	if(a[j][x]==p[i].y){
		ans+=t[j][x];
		ans+=w[j];
		return ;
	}
	for(int l;l<=k[j];l++)
	for(int z=j;z<=n;z++){
		if(a[j][x]==a[z][x]){
			ans+=t[j][x];
		    ans+=w[j];
		    dfs(i,z,l);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			for(int x=1;x<=k[j];x++){
				if(!flag&&a[j][x]==p[i].x){
				    ans+=t[j][x];
				    ans+=w[j];
				    flag=true;
				    break;
			    }   
			}
			if(flag){
				break;
			}
		}
		if(flag){
			dfs(i,1,1);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
