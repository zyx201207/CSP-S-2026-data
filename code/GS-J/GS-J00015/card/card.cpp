#include<iostream>
#include<vector>
#include<map>
#include<bitset>
#include<cstring>
using namespace std;
int stk[500005],o[500005],a[500005],ptr,n,m;
bool alive[500005],aalive[500005];
int last[500005];
map<int,vector<int> > cache;
int main(){
	
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(last[a[i]]<i){
			last[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(!aalive[a[i]]){
			
			ptr=0;
			memset(alive,0,sizeof(alive));
			
			for(int j=last[a[i]];j<=n;j++){
				if(alive[a[j]]){
					while(stk[ptr]!=a[j] && ptr>1){
						alive[stk[ptr]]=0;
						ptr--;
						
					}
					ptr--;
				}
				stk[++ptr]=a[j];
				alive[a[j]]=1;
			}
			
			for(int j=1;j<=ptr;j++){
				o[stk[j]]++;
				cache[a[i]].push_back(stk[j]);
			}
			aalive[a[i]]=1;
		}
		else{
			for(int iui:cache[a[i]]){
				o[iui]++;
			}
		}
	
	}

	for(int i=1;i<=m;i++)cout<<o[i]<<" ";
	return 0;
}

