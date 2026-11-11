#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int C,T,n;
long long ans,a[N],m,cnt,t;
bool p;
long long check(long long x,long long y){
	if(a[y]-a[x]<=m){
		return 1;
	}
	for(long long i=y-1;i>x;i--){
		if(a[i]-a[i-1]>m){
			return -0x3f3f3f3f;
		}
		if(a[i]-a[x]>m){
			return check(x,i)+1;
		}else{
			return 1;
		}
	}
}
void dfs(int x,int y,int k){
	if(p){
		return;
	}
	if(k==t){
		if(x==y){
			cnt++;
			if(cnt>2){
				p=true;
			}
		}
		return;
	}
	for(long long i=m;i>=1;i--){
		if(x+i<=y){
			dfs(x+i,y,k+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			a[i]-=a[1];
		}
		a[1]=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				t=check(i,j)+1;
				if(a[j]-a[i]<=m||a[j]-a[j-1]>m||t<0){
					continue;
				}
				p=false;
				cnt=0;
				dfs(i,j,0);
				if(!p){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

