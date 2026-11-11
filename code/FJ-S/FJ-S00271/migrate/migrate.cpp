#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,ans,a[N],dis[N],f[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(d==1)cout<<"0\n";
		else if(n<=5000){
			for(int i=1;i<=n;i++){//Æðµã 
//				cout<<i<<" :\n";
				dis[i]=0,f[i]=1;
				int s=i,p=i,cnt1=0,cnt2=1; 
				for(int j=i+1;j<=n;j++){
					while(p<s&&a[j]-a[p]>d)cnt2-=f[p++];
					if(a[j]-a[s]<=d){
						dis[j]=dis[s]+1;
						f[j]=cnt2;
						cnt1+=f[j];
					}
					else if(a[j]-a[j-1]<=d){
						dis[j]=dis[s]+2;
						p=s+1;
						s=j-1;
						while(p<s&&a[j]-a[p]>d)cnt1-=f[p++];
						f[j]=cnt1;
						cnt2=cnt1;
						cnt1=f[j];
					}
					else{
						for(int k=j;k<=n;k++)dis[k]=1e18;
						break;
					}
//					cout<<j<<" : "<<dis[j]<<" "<<f[j]<<" "<<cnt1<<" "<<cnt2<<"\n";
				}
				for(int j=i+1;j<=n;j++)
					if(f[j]==2)ans++;
//				cout<<"\n";
			}
			cout<<ans<<"\n";
		}
		else{
			int tmp=d/(a[2]-a[1]);
			if(tmp==1)cout<<"0\n";
			else cout<<max(0ll,n-(tmp+tmp)+1)<<"\n";
		}
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/ 
