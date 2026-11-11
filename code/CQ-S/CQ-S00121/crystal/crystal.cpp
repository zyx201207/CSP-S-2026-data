//75·Ö 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],ans;
bool flag=0;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			flag=1;
			break;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			int w=m,res=1;
			for(int j=i-1;j>=1;j--){
				int x=a[i]-a[j];
				if(w>=x) w-=x,res++;
			}
			ans=max(ans,res);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			m-=i*x;
			if(m<0){
				ans=i-1;
				break;
			}
		}
	}
	cout<<ans;
}
signed main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();

	return 0;
}

