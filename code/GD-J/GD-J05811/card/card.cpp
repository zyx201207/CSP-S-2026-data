#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
int n,m;
bool bol[300005];//是否存在 
int pk[500005];//初始牌库 
int dq[500005];//当前牌库 
int sc[500005];//输出数组 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pk[i];
		dq[i]=-1;
	}
	for(int i=1;i<=m;i++){
		bol[i]=false;
	}
	int tick=1,cnt=0;
	
	for(int i=1;i<=n;i++){
		//cout<<"对于第"<<i<<"局游戏，小Z打出";for(int z=i;z<=n;z++) cout<<pk[z]<<" ";cout<<"的牌\n";
		for(int j=i;j<=n;j++){
			if(!bol[pk[j]]){
				dq[tick++]=pk[j];
				//cout<<"    第"<<j<<"次操作打出"<<pk[j]<<'\n';
				bol[pk[j]]=true;
			}else{
				dq[tick--]=-1;
				while(dq[tick]!=pk[j]){
					dq[tick--]=-1;
				}//cout<<"    第"<<j<<"次操作收掉两个"<<pk[j]<<"之间的牌\n"; 
			}
		}
		int a=1;
		while(dq[a]!=-1){
			sc[dq[a]]++;
			a++;
		}
		
		for(int j=1;j<=n;j++){
			dq[i]=-1;	
		}for(int j=1;j<=m;j++){
			bol[i]=false;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<sc[i]<<" "; 
	}
	
	return 0;
} 
