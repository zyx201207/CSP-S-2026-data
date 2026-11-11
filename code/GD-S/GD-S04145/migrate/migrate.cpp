//start 16:43:29
#include<bits/stdc++.h>
#define int long long
using namespace std;
//int mini[5001][5001];
int x[2000005]={};
pair<int,bool> dfs(int i,int j,int deepth){
//	cout<<i<<' '<<j<<"  "<<deepth<<'\n';
	int mina=0x7fffffff,sum=0;
	if(abs(i-j)==1)return make_pair(abs(x[i]-x[j]),0);
	int aa[j-i];
	for(int a(i+1);a<j;a++)aa[a-i-1]=dfs(i,a,deepth+1).first+dfs(a,j,deepth+1).first,mina=min(mina,aa[a-i-1]);
	if(deepth==0){
		for(int a(i+1);a<j;a++)if(mina==aa[a-i-1])sum++;
	}
	return make_pair(mina,(sum==2));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
//		memset(mini,0,sizeof(mini));
		memset(x,0,sizeof(0));
		int n,d,ans(0); 
		cin>>n>>d;
//		bool can[n+1][n+1]={};
//		for(int i(0);i<n;i++)
//			for(int j(0);j<n;j++)
//				mini[i][j]=0x7fffffff;
		for(int i(0);i<n;i++){
			cin>>x[i];
		}
//		for(int i(0);i<n;i++){
//			for(int j(i-1);abs(x[j]-x[i])<=d&&j>=0;j--)can[i][j]=can[j][i];//=mini[i][j]=mini[j][i]=1;
//			for(int j(i+1);abs(x[j]-x[i])<=d&&j<n;j++)can[i][j]=can[j][i];//=mini[i][j]=mini[j][i]=1;
//		}
//		cout<<"ok";
//		for(int i(0);i<n;i++){
//			for(int j(0);j<n;j++){
//				cout<<can[i][j]<<' '; 
//			}
//			cout<<'\n';
//		}
//		for(int i(0);i<n;i++){
//			for(int j(0);j<n;j++){
//				if(!can[i][j])continue;
//				for(int k(0);k<n;k++){
//					if(!can[j][k])continue;
//					mini[i][k]=min(mini[i][k],mini[i][j]+mini[j][k]);
//					if(i==k)mini[i][k]=0x7fffffff;
//					mini[k][i]=mini[i][k];
//				}
//			}
//		}
		for(int i(0);i<n;i++){
			for(int j(i+1);j<n;j++){
//				cout<<mini[i][j]<<' '; 
				if(dfs(i,j,0).second)ans++;
//				cout<<i<<" "<<j<<"   "<<ans<<'\n';
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
} //QAQ 正在尝试使用时间114%的概率爆炸的算法 
//好像样例一过了17:17:40 但好像剩下都没过
//蒜鸟 end17:22:48 

/*

*/
