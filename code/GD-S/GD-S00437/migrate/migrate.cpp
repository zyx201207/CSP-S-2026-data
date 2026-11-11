#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t;
int n;
ll d,x[2000006];
int fl[5005][5005];
int mi[5005][5005];
ll ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=5000){
			for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) mi[i][j]=(i==j?0:1e9),fl[i][j]=0;
			ans=0;
			for(int i=1,l=1;i<=n;i++,l=i) for(int j=i+1;j<=n;j++){
				while(x[j]-x[l]>d) l++;
				if(l>=j) break;
				mi[i][j]=mi[i][l]+1;
			}
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
				if(mi[i][j]<=1){
					fl[i][j]=1;
					continue;
				}
				for(int l=j-1;l>=i;l--) 
					if(mi[i][l]==mi[i][j]-1&&x[j]-x[l]<=d) fl[i][j]=min(3,fl[i][j]+fl[i][l]);//cout<<i<<" "<<l<<"->"<<j<<"\n";
					else if(mi[i][l]<mi[i][j]-1||x[j]-x[l]>d) break;
	//				cout<<i<<" "<<j<<" "<<fl[i][j]<<" "<<mi[i][j]<<"\n\n";
				if(fl[i][j]==2) ans++;
			}
			cout<<ans<<"\n";		
		}
		else{
			ll dis=x[2]-x[1];
			ll cnt=d/dis;
			if(cnt>=n){
				cout<<"0\n";
				continue;
			}
			if(cnt<=1){
				cout<<"0\n";
				continue;
			}
			ans=n-(cnt*2-1);
			cout<<max(ans,0ll)<<"\n";
		}
	}
	return 0;
}

