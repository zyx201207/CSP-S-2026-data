#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
int psp[2000005];
long long mpc=1e17,cost;
int dpo=0;
long long pos[2000005];
long long dis[2000005];
void dfs(long long flr,int x,int y){
	if(x>=y){
		if(mpc==flr){
			dpo++;
		}
		mpc=min(mpc,flr);
		return;
	}
	int del=0,sum=0;
	while(sum+dis[x+del]<=d){
		del++;
		dfs(flr+1,x+del,y);
	}
	return;
}
bool chk(int x,int y){
	memset(psp,0,sizeof(psp));
	
	bool dpip=1;
	int dx=y-x,arr=0;
	for(int i=x;i<=y;i++){
		if(psp[arr]+dis[i]>d){
			arr++;
		}
		psp[arr]+=dis[i];
		//arr+1=min(l)
	}
	mpc=arr+1;
	for(int i=x;i<=y;i++){
		dpo=0;
		dfs(1,x,y);
		//arr+1=min(l)
	}
	
	return dpo==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int u=0;u<t;u++){
		int cnt=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>pos[i];
			if(i>0){
				dis[i-1]=pos[i]-pos[i-1];
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(chk(i,j)){
				cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
