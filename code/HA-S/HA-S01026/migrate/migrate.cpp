#include<bits/stdc++.h>
using namespace std;

int test_id,question;
int n,d;
int x[11];
struct answer{
	int minn=11,cnt=0;
}cnt[11][11]={};

void dfs(int t,int st,int ed,int sum){
	if(t==ed){
		if (sum<cnt[st][ed].minn){
			cnt[st][ed].minn=sum;
			cnt[st][ed].cnt=1;
		}else if(sum==cnt[st][ed].minn) cnt[st][ed].cnt++;
	}else{
		for (int i=t+1;x[i]-x[t]<=d && i<=ed ;i++){
			dfs(i,st,ed,sum+1);
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>test_id>>question;
	while(question--){
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				{cnt[i][j].cnt=-1,cnt[i][j].minn=11;}
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,i,j,0);
			}
		}
		
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) 
				if(cnt[i][j].cnt==2) ans++;
		
		cout<<ans<<"\n";
	}
	
	
	
	
	
	return 0;
}