#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,kk[505],ans=1000000000;
int zt[505],s[505][505],t[505][505];
bool vis[505][505];
void asd(int x,int y,int t1,int hs){
	if(x+1>kk[x]||x-1<0)return ;
	if(x==y){
		ans=min(ans,t1);
		return ;
		
	}
	vis[hs][x]=1;
	asd(x+1,y,t1+=t[hs][x+1],hs);
	for(int i=hs+1;i<=n;i++){
		for(int j=1;j<=kk[i];j++)
		{
			if(s[i][j]==s[hs][x])asd( j+1,y,t1+=t[i][j+1],i);
		}
	}
	asd(x-1,y,t1+=t[hs][x-1],hs);
	for(int i=hs+1;i<=n;i++){
		for(int j=1;j<=kk[i];j++)
		{
			if(s[i][j]==s[hs][x])asd( j-1,y,t1+=t[i][j-1],i);
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	int op=0;
	for(int i=1;i<=m;i++)cin>>zt[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		kk[i]=k;op++;
		for(int j=1;j<=k;j++)cin>>s[i][j]>>t[i][j];
	}
	for(int le=1;le<=q;le++){
		int ks,js;
		cin>>ks>>js;//msmset(k,0,sizeof())
		cout<<"!!!!"<<endl;
		asd(ks,js,zt[ks],1);/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<op;j++){
				if(s[i][j]==ks)
			}
			
		}*/
		
	}
	cout<<ans;
	return 0;
} 
