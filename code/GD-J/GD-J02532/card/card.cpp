#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=3e5+10;
int n,m,a[maxn];
int ans[maxn];
bool vis[maxm];
int d[maxn];//存每个牌的位置cnt 
int dc[maxn];//存每个位置对应的牌x
int sum[maxm];
int st[maxm];
void solve1(){//暴力,n<=500
	int cnt=0;
	for(int i=1;i<=n;i++){//枚举n轮 
		cnt=0;
		for(int j=i;j<=n;j++){//模拟每轮
			int x=a[j];
			if(!vis[x]){//桌上无同点数的牌
				vis[x]=true;
			}
			else{
				for(int k=d[x];k<=cnt;k++){//被拿走的牌
					int num=dc[k];
					vis[num]=false;
				}
			}
			cnt++;
			//双向索引 
			d[x]=cnt;
			dc[cnt]=x;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){//该轮结束后仍在桌上 
				ans[j]++;
				vis[j]=false;//初始化 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
void solveA(){
	for(int i=1;i<=n;i++){
		if(sum[a[i]]==0){
			st[a[i]]=i;
		}
		sum[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(sum[i]%2==0){
			ans[i]=1;
		}
		else{
			ans[i]=st[i]+sum[i]/2;
		}
		cout<<ans[i]<<" ";
	}
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		solve1();
	}
	else{
		solveA();
	}
	return 0;
}
