#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans,minn;
bool flag;
int a[2000020],appear[2000020],vis[2000020];
int se(int x,int y,int len){
	vis[x]=1;
	if(x==y){
		if(len<minn){
			ans=1;
			minn=len;
		}
		else if(len==minn){
			ans++;
			if(ans==2){
				flag=1;
			}
			if(ans>2){
				flag=0;
			}
		}
		return len;
	}
	for(int i=x+1;i<=x+d;i++){
		if((appear[i])&&!vis[i]){
			vis[i]=1;
			se(i,y,len+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migarte.out","w",stdout);
	cin>>c>>t;
	for(int algd=1;algd<=t;algd++){
		memset(a,0,sizeof(a));
		memset(appear,0,sizeof(appear));
		memset(vis,0,sizeof(vis));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			appear[a[i]]=1;
		}
		int ans,lastans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=1,minn=0x3f3f3f,flag=0;
				se(i,j,0);
				if(flag==1){
					lastans+=1;
				}
			}
		}
		cout<<lastans;
		if(algd<t){
			cout<<endl; 
		}
	}
	return 0;
}
