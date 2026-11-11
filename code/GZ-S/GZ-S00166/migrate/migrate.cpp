//GZ-S00166 甘梓辰 贵阳市第一中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000005],fa[2000005],cnt[2000005][3],t,cal[2000005];
void solve(){
	int ans=0;
	cin>>n>>d;
	fa[n+1]=fa[n+2]=n+5;
//	if(t==3) cout<<n<<" "<<d<<endl;
	for(int i=1;i<=n;i++){
		cin>>x[i];
//		if(t==3) cout<<x[i]<<" ";
		fa[i]=fa[i-1];
		if(i==1){
			fa[i]=1;
			continue;
		}
		while(x[i]-x[fa[i]]>d){
			fa[i]++;
		}
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(x[j]-x[i]<=d){
//				cout<<i<<" "<<j<<endl;
//			}
//		}
//	}
	for(int i=n;i>0;i--){
//		cout<<i<<"　"<<cnt[i][0]<<"　"<<cnt[i][1]<<endl; 
		if(fa[i]==i){
			cnt[i][0]=cnt[i][1]=0;
			continue;
		}
		cnt[fa[i]][0]++;
		if(cnt[i][0]){
			int l=fa[i],r=i-1,pl=i,pr;
			pl=fa[i+1];
			l=pl,r=i-1,pr=pl-1;
			if(i+2<=n){
				pr=min(i-1,fa[i+2]-1);
			}else{
				pr=i-1;
			}
			if(pl>fa[i]+1){
				cnt[fa[i]][0]+=cnt[i][0];
			}else if(pl==fa[i]&&pl<=pr){
				cnt[fa[i]][1]+=cnt[i][0];
			}else if(pl==fa[i]+1){
				cnt[fa[i]][2]+=cnt[i][0];
			}
			ans+=(pr-pl+1)*cnt[i][0];
		}
		if(cnt[i][1]){
			int l=fa[i],r=i-1,p=fa[i]-1;
			p=min(i-1,fa[i+1]-1);
			ans+=(p-fa[i]+1)*cnt[i][1];
			if(p>=fa[i]){
				cnt[fa[i]][1]+=cnt[i][1]; 
			}
		}
		if(cnt[i][2]){
			int pl=fa[i],pr=fa[i+1]-1;
			if(pl==pr){
				cnt[fa[i]][2]+=cnt[i][2];
			}else if(pl<pr){
				cnt[fa[i]][0]+=cnt[i][2];
			}
		}
		cnt[i][0]=cnt[i][1]=cnt[i][2]=0;
	}
	cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
    	solve();
	}
	return 0;
}

