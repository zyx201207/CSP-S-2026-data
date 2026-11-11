#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[m+1];
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int subs[n+1][m+1];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=m;j++)
			subs[i][j]=0;
	for(int i=1;i<=n;i++){
		int joker;
		cin>>joker;
		for(int j=1;j<=joker;j++){
			int a,t;
			cin>>a>>t;
			subs[i][a]=t;
		}
	}
	while(q--){
		int st,en;
		cin>>st>>en;
		int ans=0;
		ans+=w[st];
		for(int i=1;i<=n;i++){
			if(subs[i][st]!=0){
				ans+=subs[i][st];
				break;
			}
		}
		int youmeiyou[m+1];
		for(int i=1;i<=m;i++)
			youmeiyou[i]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(subs[i][j]==0)
					youmeiyou[j]=0;
			}
		}
		int sm,realsm=0;
		for(int i=1;i<=m;i++){
			if(youmeiyou[i]==1){
				for(int j=1;j<=n;j++){
					sm+=subs[j][i];
					if(realsm==0)
						realsm=sm;
					else
						realsm=min(sm,realsm);
				}
			}	
		}
		ans+=realsm;
		for(int i=1;i<=m;i++){
			if(youmeiyou[i]==1){
				ans+=subs[2][en];
			}	
		}
		ans+=w[en];
		cout<<ans<<"\n";
	}
	return 0;
}
