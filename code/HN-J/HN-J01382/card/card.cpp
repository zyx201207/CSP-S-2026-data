#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int ans[N],a[N],dui_l[N],dui[N];
bool vis[N];
int n,m,k,l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(dui_l[a[i]]==0){
			dui_l[a[i]]=i;
		}else{
			dui[dui_l[a[i]]]=i;
			dui[i]=dui_l[a[i]];
			dui_l[a[i]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		memset(vis,true,(n+1));
		for(int j=i;j<=n;){
			if(dui[j]!=0&&dui[j]>=j) j=dui[j]+1;
			else if(vis[j]) ans[i]++,vis[i]=false,j++;
			else j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
