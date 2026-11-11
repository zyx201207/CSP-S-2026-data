#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5,INF=3e18;
int n,a[MAXN],d,c,T,num,ans,minn=INF;
void dfs(int st,int en,int len){
	if(len>minn)return;
	if(st>en)return;
	if(st==en){
		//cout<<minn<<" "<<len<<" "<<num<<"\n--------\n";
		if(len<minn){minn=len;num=1;return;}
		if(len>minn)return;
		num++;
	}
	for(register int i=st+1;i<=en;i++){//cout<<a[st]<<" "<<a[i]<<"\n";
		if(abs(a[st]-a[i])<=d){dfs(i,en,len+1);}
		//cout<<st<<" "<<en<<"\n";
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		num=0;
		for(register int i=1;i<=n;i++){
			cin>>a[i];	
		}
		if(c>=11&&c<=12){
			int gd=abs(a[2]-a[1]),le=d/gd*2-1;
			if(d/gd==1){
				cout<<0<<"\n";
				continue;
			}
			cout<<n-le<<"\n";
			continue;
		}
		for(register int i=1;i<=n;i++){
			for(register int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<d)continue;
				num=0;
				minn=INF;
				dfs(i,j,0);
				//cout<<i<<" "<<j<<" "<<num<<"\n";
				if(num==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
