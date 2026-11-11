//华东师范大学附属贵阳学校 刘睿羽 GZ-J00398   
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,m;
int vis[N];
int a[N];
int maxn;
int zs[N][N];
int decision(int x,int y){
	int ans=0,f=1;
	while(x!=0&&y!=0){
		int tx=x%2,ty=y%2;
		x/=2,y/=2;
		ans+=f*(tx&&ty);
		f*=2;
	}
	return ans;
}
void dfs(int k,int cnt){
	if (k>=m) {
		maxn=max(maxn,cnt);
		return; 
	}
	else{
		for (int i=1;i<=n;i++){
			if (k==1) cnt=a[i];
			if (vis[i]==0){
				vis[i]=1;	
			    dfs(k++,decision(cnt,a[i]));
				vis[i]=0;
			}
			
		}
		
	}
	return;
}

signed main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (m!=2) dfs(1,0);
    else{
    	for (int i=1;i<=n;i++){
    		for (int j=i;j<=n;j++){
    			maxn=max(maxn,decision(a[i],a[j]));
			}
		}
	}
    cout<<maxn;
	return 0; 
}

