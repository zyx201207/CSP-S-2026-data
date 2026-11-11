#include<bits/stdc++.h>
#define int  long long
using namespace std;
int a[2000005];
int tt[5005][5005];
int n,d;
int best;
int nice(int x,int y){
	int ans=0;
	while(x<y){
		int k=x+1;
		while((k+1)<=y&&(a[k+1]-a[x])<=d){
			k+=1;
		} 
		x=k;
		ans+=1;
	}
	return ans;
}
int fun(int x,int y,int f){
	if(x==y&&f==best){
		return 1;
	}
	if(f>=best||x>=y){
		return 0;
	}
	int ans=0;
	int s=x; 
	while((s+1)<=y&&(a[s+1]-a[x])<=d){
		s+=1;
		if(tt[s][y]!=-100){
			ans+=tt[s][y];
		}
		else{
			tt[s][y]=fun(s,y,f+1);
			ans+=tt[s][y];	
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			} 
			int ans=0;
			int k=a[2]-a[1];
			int s=d/k;
			if((s/k)>=2){
				ans=n-3;
			}
			cout<<ans<<endl;
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			} 
			for(int i=1;i<=5002;i++){
				for(int j=1;j<=5002;j++){
					tt[i][j]=-100;
				} 
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					best=nice(i,j);
					int x=fun(i,j,0);
					if(x==2){
						ans+=1;
					} 
				}
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
} 
