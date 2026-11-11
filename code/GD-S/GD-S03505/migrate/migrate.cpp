#include<bits/stdc++.h>
using namespace std;
int c,t;	int n,d;
int s[2000005],mp[2000005]={2000005};
int vis[2000005];
void asd(int x,int y){
	if(x>=n||(abs(s[x]-s[x+1])>d)){
	
		return;
	}
	mp[x]=min(mp[x],y);
//	cout<<mp[x]<<endl;
	for(int i=1;i<=n;i++){
		if(abs(s[x]-s[x+i])<=d){
		//	cout<<x<<" "<<i+x<<" "<<y<<endl;
			asd(x+i,y+1);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	while(t--){
		
		int ans=0;
		cin>>n>>d;
		memset(s,0,sizeof(s));
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}for(int i=1;i<=n;i++)mp[i]=2000005;
		asd(1,0);
		
		for(int i=1;i<=n;i++){
			vis[mp[i]]++;
		//	cout<<vis[mp[i]]<<" ";
		}
	//	cout<<endl;
		for(int i=1;i<=n;i++){
		//	cout<<vis[i]<<" ";
			if(vis[mp[i]]==2){ans++;//	cout<<"!!!!"<<endl;
			}
		}
		if(ans==0)cout<<ans<<endl;
		else cout<<ans-1<<endl;
		
	}
	return 0;
} 
