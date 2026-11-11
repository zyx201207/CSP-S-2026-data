#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],f[200010],ss,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1;
	}
	for(int i=30;i>=0;i--){
		ss=0;
		for(int j=1;j<=n;j++){
			if(!f[j])continue;
			if((a[j]&(1<<i)))ss++;
		}
		if(ss>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1<<i))){
					f[j]=0;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
