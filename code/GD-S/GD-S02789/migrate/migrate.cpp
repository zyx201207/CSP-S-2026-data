#include<bits/stdc++.h>
#define int long long
using namespace std;
int cx,t;
int n,d,a[2000006],b[2000006],ans=0;
signed main(){
	//freopen("migrate1.in","r",stdin);
	//freopen("migrate1.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>cx>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			bool f[2000006];
			int aj[2000006];
			for(int j=i;j<=n;j++)  f[j]=0x3f3f3f3f3f3f3f3f,aj[j]=0;
			f[i]=0,aj[i]=1;
			for(int j=i;j<=n;j++){
				int fo=f[j];
				for(int k=j+1;k<=n;k++){
					if(a[k]-a[j]>d)  break;
					else if(f[k]>fo+1)  aj[k]=aj[j],f[k]=fo+1;
					else  aj[k]+=aj[j];
				}
			}
			for(int j=i+1;j<=n;j++){
				cout<<f[j]<<' '<<aj[j]<<'\n';
				if(aj[j]==2){
					ans++;
				}
			}cout<<'\n';
		}cout<<ans<<'\n';
	}
	return 0;
} 
