#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn],k[maxn],lst[maxn];
int ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int now=i;
		for(int j=i;j<=n;j++){
			if(lst[a[j]]){
				for(int x=lst[a[i]];x<now;x++){
					k[x]=0;
				}		
				now=lst[a[i]];
	
			}
			k[now]=a[j];
			lst[a[j]]=now;
			now++;
		}
		for(int j=1;j<=m;j++){
			lst[j]=0;
		}
		for(int j=i;j<=now;j++){
			ans[k[j]]++;
			k[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
