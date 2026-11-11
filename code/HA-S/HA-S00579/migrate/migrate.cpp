#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans=0,anst=1,num=0,w=0,u=2;
int bfs(int x,int y,int s2[10001],int d1){
	//判断x,y最小路径
	if(x==y) return ++w;
	 if(s2[x+1]-s2[x]<=d1){
	 	d1=d1-s2[x+1]+s2[x];
		bfs(++x,y,s2,d1);
	 }else{
	 	w++;
	 	bfs(--x,y,s2,d);
	 	//return w;
	 } 
}
int dfs(int x,int y,int s2[10001],int d1){
	//判断x,y最小路径
	if(x==y) return ++w;
	 if(s2[y]-s2[y-1]<=d1){
	 	d1=d1-s2[y]+s2[y-1];
		dfs(x,--y,s2,d1);
	 }else{
	 	w++;
	 	dfs(++y,x,s2,d);
	 	return w;
	 } 
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
for(int q=1;q<=t;q++){
	cin>>n>>d;
	int s1[n+1];
	for(int i=1;i<=n;i++)
		cin>>s1[i];

	for(int j=1;j<=n;j++){
		int ss=0;
		int s;
		 num=0;
		 anst=0;
	for(int i=j+1;i<=n;i++){
			u=2;
			while(u){
			if(u==2) s+=bfs(j,i,s1,d);
			if(u==1) ss+=dfs(j,i,s1,d);
			w=0;
						
			u--;
		}
		if(s==ss) anst++;
		if(anst==2) ans++;
		}


}
cout<<ans<<endl;}
	return 0;
	}
