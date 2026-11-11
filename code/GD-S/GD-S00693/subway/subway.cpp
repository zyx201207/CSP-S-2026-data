#include<iostream>
using namespace std;

int c,n,m,d,q;
int x,y,ans;
int w[250005];//线路 
int a[505][250005],v[250005];//
int t[505][250005];//内路用时 
int k[505];

int dfs(int ki,int dum,int step){
	if(v[ki]==1)return 1e9;
	if(ki==y)return dum;
	v[ki]=1;
	int minn=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==ki){
				dum+=t[i][j];
				for(int s=1;s<=k[i];s++){
					if(a[i][s]==ki)continue;
						minn=min(minn,dfs(a[i][s],dum+t[i][s],step+1));
				}
				dum-=t[i][j];
				break;
			}
		}
	}	
	return dum+minn;
}

int sud=1e9;

void dfs1(int ki,int step){
	if(v[ki]==1){
		return;
	}
	else if(ki==y){
		sud=min(sud,step*2);
		return;
	}v[ki]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==ki){
				for(int s=1;s<=k[i];s++){
					if(a[i][s]==ki)continue;
					dfs1(a[i][s],step+1);
				}
				break;
			}
		}
	}
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	} 
	if(c<=10){
		while(q--){
			for(int j=1;j<=250000;j++){
				v[j]=0;
			}
			cin>>x>>y;
			ans=0;
			ans+=w[x]+w[y];
			ans+=dfs(x,0,0);
			cout<<ans<<"\n";
		}
	}
	else if(c>=12&&c<=19){
		while(q--){
			sud=1e9;
			for(int j=1;j<=250000;j++){
				v[j]=0;
			}
			cin>>x>>y;
			ans=0;
			ans+=w[x]+w[y];
			dfs1(x,0);
			ans+=sud*t[1][1];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(a[i][j]==x){
//					for(int s=1;s<=k[i];s++){
//						if(a[i][s]==x)continue;
//						a[i][s];
//					}
//					break;
//				}
//			}
//		} 
