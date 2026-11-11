#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000006],ans;
int zd(int from,int to){
	long long stp=0;
	for(long long i=from,lst=from;i<=to;++i){
		if(i!=from&&x[i]-x[i-1]>d){
			return 0;
		}
		if(x[i]-x[lst]>d){
			stp++;
			lst=i-1;
			i--;
		}
		if(i==to){
			stp++;
			break;
		}		
	}
	return stp;
}
int top,tot;
void dfs(int now,int to,int step){
	if(tot>=3){
		return ;
	}
	if(now>=to&&step==top){
		tot++;
		return ;
	}
	if(step==top&&now!=to){
		return ;
	}
	int i=now;
	for(;x[i]-x[now]<=d;i++){
		
	}
	for(;i>=now;i--){
		dfs(i,to,step+1);
	}
}
void fst(){
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			tot=0;
			top=zd(i,j);
			dfs(i,j,0);
			if(tot==2){
				ans++;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%d",&x[i]);
		}
//		cout<<zd(1,4)<<"\n";
//		cout<<zd(2,4)<<"\n";
//		cout<<zd(1,5)<<"\n";
		fst();
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

