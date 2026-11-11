#include <bits/stdc++.h>
using namespace std;

long long n,m;//输入牌数量和卡牌数字数量 
const int MAXN= 0x3f3f3f3f;
int a[MAXN];//初始化 
int card[MAXN];//初始化卡牌列表 
int tmp[MAXN];//初始化输出用列表 
int panduan[MAXN];
bool vis[MAXN];


int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];//输入n张卡牌的价值 
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<n;i++){                  //先检索牌的数量 
			for(int j=0;j<i;j++){				//再检查剩下牌的数量（跳过已经检查的） 
				if (panduan[j]==card[i]){		//如果已经有了这张牌，那就添加进桌面的牌并且把前面的那些牌都设置为不检查 
					panduan[i]=card[i];
					vis[0,j]=false;
				}
				else{                           //如果没有这张牌，说明这是新牌，添加进去并设置为检查 
					panduan[i] = card[i];
					vis[i]=true;	                                 
				}
			}
		}
		for(int i=0;i<=n;i++){
			if(vis[i]){
				tmp[i]+=1;
			}
		}
	
		for(int k=0;k<m;k++){
			card[k]=card[k+1];
		}
		n-=1;
	}
	for(int m=0;m<=sizeof(tmp);m++){
		cout<<tmp[m];
	}
	return 0;
}
