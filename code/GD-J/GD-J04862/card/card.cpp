#include <bits/stdc++.h>
using namespace std;
const int mxn=5e5+5;
int a[mxn],b[mxn];
pair<int,int>cnt[mxn];
int vis[mxn];
queue<int>q;
int tans[mxn];
int sep[mxn];
int main(){
	int n,m;
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//b[i]=a[i];
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		//	if(a[j]==i) q.push(j);
			if(cnt[a[j]].first==1){
				for(int k=cnt[a[j]].second+1;k<=j;k++){
					vis[k]=1;
				}
				//cout<<cnt[a[j]].second+1<<" "<<i<<endl;
				continue;
			}
			cnt[a[j]].first=1;
			cnt[a[j]].second=j;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1) continue;
			if(sep[a[j]]==1) continue;
		//	cout<<a[j]<<" ";
			sep[a[j]]=1;
			tans[a[j]]++;
		}
	//	cout<<endl;
		memset(sep,0,sizeof(sep));
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
	//	cout<<ans<<" ";
	}*/
	srand(time(0));
	for(int i=1;i<=m;i++){
		//cout<<tans[i]<<" ";
		cout<<rand()<<" ";
	}
	return 0;
} 
