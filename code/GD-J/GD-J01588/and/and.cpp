#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,B=35;
int n,a[N],cnt[B],m,ans;
bool ok[N];
inline void update(int x,int up){
	for(int i=0;i<=30;i++){
		if(x&(1<<i))cnt[i]+=up;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(a[i],1);
	}
	memset(ok,1,sizeof ok);
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!ok[j])continue;
				if(!(a[j]&(1<<i))){
					ok[j]=0;
					update(a[j],-1);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
