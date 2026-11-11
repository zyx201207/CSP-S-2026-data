#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
int C,T;
int n,m;
int a[2000005],f[2000005],f2[2000005];
void work(){
	int x=a[2]-a[1],y=m/x;
	if(y==0||y==1){
		cout<<"0\n";
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(i+y*2-1<=n)ans++;else break;
	cout<<ans<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(C==11||C==12){
			work();
			continue;
		}
		for(int i=1;i<=n;i++){
			f[i]=0,f2[i]=1;
			for(int k=i+1;k<=n;k++){
				f[k]=INF,f2[k]=0;
				for(int l=k-1;l>=i;l--){
					if(a[k]-a[l]>m)break;
					if(f[l]+1==f[k])f2[k]+=f2[l];
					if(f[l]+1<f[k])f2[k]=f2[l],f[k]=f[l]+1;
				}
				if(f2[k]==2)ans++;
			}
		}
		cout<<ans<<"\n";
		
	}
	
	
	return 0;
}
