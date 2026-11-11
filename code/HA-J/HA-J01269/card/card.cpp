#include<bits/stdc++.h>
#define int long long
using namespace std;
int dn,dm,d[500010],dns,dis[500010];
bool dlag[500010];
unordered_map<int,int > dmp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>dn>>dm;
	for(int i=1;i<=dn;i++) cin>>d[i];
	for(int i=1;i<=dn;i++){
		for(int j=0;j<=dn;j++) dis[j]=0;
		memset(dlag,false,sizeof dlag);
		for(int j=i;j<=dn;j++){
			bool dlag1=0;int df;
			for(int k=i;k<=j-1;k++){
				if(d[k]==d[j]&&dis[k]==0){
					dlag1=1,df=k;
					break;
				}
			}
			if(dlag1){
				for(int k=df;k<=j-1;k++){
					dis[k]=1;
				}
			}
		}
		for(int j=i;j<=dn;j++){
			if(dis[j]==0&&!dlag[d[j]]){
				dmp[d[j]]++,dlag[d[j]]=1;
			}
		}
	}
	for(int i=1;i<=dm;i++){
		cout<<dmp[i]<<' ';
	}
	return 0;
}
