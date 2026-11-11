#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=5e5+10,N2=3e5+10;
ll n,m;
int aa[N];
int ans[N2];
bool flag[N2];
int mark[N2],last[N2];
//mark记录是j的卡之前出现的位置下标,包含j本身 （从一开始） 
//flag记录在内的已出现点数 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	
	for(int i=0;i<n;i++){
		int cnt=1;//从一开始 
		for(int j=i+1;j<=n;j++){
			int k=aa[j];
			if(!flag[k]){
				last[cnt]=k;
				mark[k]=cnt;
				cnt++;
				flag[k]=1;
			}else{//换标记 
				for(int u=mark[k]+1;u<cnt;u++){
					flag[last[u]]=0;
				}
				cnt=mark[k];
				cnt++;
				flag[k]=1;
			}
		}			
		for(int u=1;u<=cnt;u++){
			//df
			//cout<<last[u]<<" ";
			ans[last[u]]++;	
			flag[u]=0;
			mark[u]=0;
			last[u]=0;
		}	 
		//df
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
