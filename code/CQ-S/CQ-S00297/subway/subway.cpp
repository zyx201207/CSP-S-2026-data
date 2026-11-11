#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,w[50005],x,y,ans;
struct ff{
	long long int b[25],t[25],tot=0;
}a[50005];
bool f[50005];
long long int xx[505][50005];
void dfs(long long int z,long long int anss,long long int xl){
	if(anss>=ans)return;
	//cout<<xl<<" "<<z<<endl;
	//if(f[z]==1)return ;
	//cout<<xl<<" "<<z<<endl;
	if(z==y){
		//cout<<"*"<<endl;
		long long int nnn;
		for(int i=1;i<=a[z].tot ;i++){
			if(a[z].b[i]==xl){
				nnn=a[z].t[i];
				break;
			}
		}
		//cout<<anss<<endl;
		//cout<<xl<<" "<<anss<<endl;
		//cout<<nnn<<endl;;
		//cout<<anss<<"^^^"<<endl;//
		ans=min(ans,anss);
		return ;
	}
	//cout<<z<<"*"<<endl;
	long long int nnn;
	//for(int i=1;i<=a[z].tot ;i++){
	//	if(a[z].b[i]==xl){
	//		nnn=a[z].t[i];
	//		break;
	//	}
	//}
	//cout<<nnn<<" "<<xl<<" "<<z<<" "<<anss<<endl;//
	//anss+=nnn;
	//cout<<anss<<endl;//
	int tot_=1;
	while(xx[xl][tot_]!=0){
		//cout<<xx[xl][tot_]<<endl;
		//cout<<f[xx[xl][tot_]]<<" "<<xx[xl][tot_]<<endl;
		//cout<<tot_<<"*"<<xx[xl][tot_]<<" "<<z<<endl;
		if(f[xx[xl][tot_]]==0){
			for(int j=1;j<=a[xx[xl][tot_]].tot ;j++){
				if(a[xx[xl][tot_]].b[j]==xl){
					nnn=a[xx[xl][tot_]].t[j];
					break;
				}
			}
			//cout<<tot_<<"("<<endl;
			for(int j=1;j<=a[xx[xl][tot_]].tot ;j++){
				//cout<<xx[xl][tot_]<<" "<<a[xx[xl][tot_]].b[j]<<" "<<tot_<<" "<<xl<<" "<<z<<endl;//
				//cout<<a[xx[xl][tot_]].b[j]<<endl;
				//cout<<anss+w[xx[xl][tot_]]<<" "<<w[xx[xl][tot_]]<<endl;
				//cout<<a[xx[xl][tot_]].b[j]<<" "<<xx[xl][tot_]<<" "<<xl<<" "<<z<<endl;//
				if(a[xx[xl][tot_]].b[j]==xl){
					f[xx[xl][tot_]]=1;
					dfs(xx[xl][tot_],anss+a[xx[xl][tot_]].t[j],a[xx[xl][tot_]].b[j]);
					f[xx[xl][tot_]]=0;
				}
				else {
					f[xx[xl][tot_]]=1;
					dfs(xx[xl][tot_],anss+a[xx[xl][tot_]].t[j]+nnn,a[xx[xl][tot_]].b[j]);
					f[xx[xl][tot_]]=0;
				}
			}
		}
		tot_++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int d;
		cin>>d;
		for(int j=1;j<=d;++j){
			long long int bb,tt;
			cin>>bb>>tt;
			a[bb].b[++a[bb].tot ]=i;
			a[bb].t[a[bb].tot ]=tt;
			xx[i][j]=bb;
		}
	}
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=d;++j){
			cout<<xx[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		for(int ii=1;ii<=m;++ii)f[ii]=0;
		//for(int i=1;i<=m;i++)cout<<f[i]<<endl;
		ans=INT_MAX;
		cin>>x>>y;
		//cout<<a[x].b[1]<<endl;
		for(int j=1;j<=a[x].tot ;j++)/*cout<<w[x]+w[y]+a[x].t[j]<<"*"<<endl,*/dfs(x,w[x]+w[y]+a[x].t[j],a[x].b[j]);
		cout<<ans<<endl;
	}
	return 0;
}//3
//好孩子，God是会保佑你的 
