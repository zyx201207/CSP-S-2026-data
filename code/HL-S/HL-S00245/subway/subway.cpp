#include<bits/stdc++.h>

using namespace std;

int n,m,c,d,q,w[500005],a[5005][5005],t[5005][5005],mp[5005][5005];
int maps[5005][5005],vis[505][505][50],belongs[5005][5005],ans=0x3f3f3f3f;

void dfs(int arr,int arrsub,int money,int targe){
	//边界就是我们找到了目标点
	if(arr==targe){
//		cout<<"arrsub= "<<arrsub<<endl;
//		cout<<"ans1= "<<ans<<endl;
		int arr1=-1;
		for(int i=1;i<=50;i++){
			if(a[arrsub][i]==targe){
//				cout<<"the station"<<i<<endl;
				arr1=i;break;
			}
		}
//		cout<<"i add money by going to the station,spend="<<t[arrsub][arr1]<<endl;
		money+=t[arrsub][arr1];
		ans=min(ans,money);
//		cout<<"arr= "<<arr<<" ans= "<<ans<<endl;
		return;
	}bool f=0;
	//我们当前处在这个点 让我们看一下哪些点可以与这个点相连 或者我们可以通过这个点换乘到哪条线上 
	for(int i=1;i<=500;i++){
		if(maps[arr][i]==1){
			f=0;
//			cout<<"i am going from "<<arr<<" to "<<i<<endl; 
			if(arrsub!=belongs[arr][i]){
				f=1;
				//当前所在的铁路不是这条路线所在的铁路，我们要换线 
//				cout<<"arrsub= "<<arrsub<<" gotosub= "<<belongs[arr][i]<<endl;
				//如果我们需要换乘 
				int arr1=-1,arr2=-1; 
				//belongs[arr][i]就是arr到i的路线在哪条铁路上 
				for(int k=1;k<=50;k++){
					if(a[arrsub][k]==arr){
						 arr1=k;break;
					}
				}
				//arr1就是当前所在点是当前所在铁路的第几个点 
				for(int k=1;k<=50;k++){
					if(a[belongs[arr][i]][k]==arr){
						arr2=k;break;
					}
				}
				//arr2就是当前所在点是我们想换乘铁路的第几个点 
				//现在我们找到了当前点是所属铁路的第几个点 要换乘的话换乘过去的点是换乘后铁路线的第几个点 接下来我们用t数组对应的点来计算换乘的时间
//				cout<<" change the subway from "<<arrsub<<" to "<<belongs[arr][i]<<"spend "<<(t[arrsub][arr1]+t[belongs[arr][i]][arr2])<<endl;
				money+=(t[arrsub][arr1]+t[belongs[arr][i]][arr2]);
			}
			//如果我们不需要换乘
			if(vis[arr][i][arrsub]==0){
				if(f==1){
					vis[arr][i][arrsub]=vis[i][arr][arrsub]=1;
					dfs(i,belongs[arr][i],money,targe);
					vis[arr][i][arrsub]=vis[i][arr][arrsub]=0;
				}else{
					vis[arr][i][arrsub]=vis[i][arr][arrsub]=1;
					dfs(i,arrsub,money,targe);
					vis[arr][i][arrsub]=vis[i][arr][arrsub]=0; //回溯 
				}
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
		int k;
		cin>>k;
		int arg=1;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]][arg++]=i;
			if(j>1){
				belongs[a[i][j]][a[i][j-1]]=belongs[a[i][j-1]][a[i][j]]=i;
				maps[a[i][j]][a[i][j-1]]=1,maps[a[i][j-1]][a[i][j]]=1;
			}
		}
	}
//	for(int i=1;i<=10;i++){
//		for(int j=1;j<=10;j++){
//			if(maps[i][j]==1){
//				cout<<"i= "<<i<<" j= "<<j<<" subwayid= "<<belongs[i][j]<<endl;
//			}
//		}
//	}
	while(q--){
		ans=0x3f3f3f3f;
		int starts=-1;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=50;i++){
			if(maps[x][i]==1){
				memset(vis,0,sizeof vis);
				int arr1=-1;
				starts=belongs[x][i];
				for(int k=1;k<=50;k++){
					if(a[belongs[x][i]][k]==x){
						 arr1=k;break;
					}
				}//找一下我们的出发点是这条铁路的第几个点 
				dfs(x,starts,t[starts][arr1],y);
			}
		}
		//vis的含义是我已经走过从i到j在第k条铁路上的路了
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
