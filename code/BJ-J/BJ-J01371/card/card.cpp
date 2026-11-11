#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[5005],ans[10005],table[3005],t=0,b[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(table,0,sizeof table);
		memset(b,0,sizeof b);
		t=0;
		for(int j=i;j<=n;j++){
			if(table[a[j]]==0){
				table[a[j]]=t+1;
				b[++t]=a[j];
			}else{
				for(int k=table[a[j]]+1;k<=t;k++){
					table[b[k]]=0;
				}
				t=table[a[j]];
			}
		}
		for(int j=1;j<=m;j++){
			//cout<<table[j]<<" ";
			ans[j]+=(table[j]>0 ? 1 : 0);
		}
		//cout<<"\n";
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
//ACACACACACACACACACACACACACACAC
