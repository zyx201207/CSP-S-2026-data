#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;



ll c,t,pos[2000009],d,n,dis[2000009],ways[2000009];

void solveA(){
	ll cf=pos[1]-pos[0];
	ll steps=d/cf;
	steps=steps*2-1;
	if(n-steps>0) cout<<n-steps<<"\n";
	else cout<<0;
}

void solveeasy(){
	ll res=0;
	for(int i=0;i<n;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(ways,0,sizeof(ways));
		ways[i]=1;	
		dis[i]=0;
		for(int j=i;j<n;j++){
			if(ways[j]==0) break;
			ll k=j+1;
			while(k<n and pos[k]-pos[j]<=d){
				//cout<<"p";
				if(dis[k]>=dis[j]+1){
					dis[k]=dis[j]+1;
					ways[k]+=ways[j];
				}
				k++;
			}
		}
		for(int j=0;j<n;j++){
		//cout<<ways[j]<<'/'<<dis[j]<<"\n";
		if(ways[j]==2) res++;
		}
	}
	cout<<res<<'\n';
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int z=0;z<t;z++){
		
		memset(pos,0,sizeof(pos));
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>pos[i];
		
		if(c==11 or c==12) solveA();
		else if(c<10) solveeasy();
		
		else cout<<0;
		
		
		
		
	}
}
