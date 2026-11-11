#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5; 
int n,m;
int a[maxn];
int lst[maxn];
int tong[maxn];
int L[maxn],R[maxn];
bool vis[maxn],vis2[maxn];
void work(int x){
	for(int i=1;i<=m;i++) vis2[i]=false;
	for(int i=1;i<=n;i++) vis[i]=false;
	for(int i=1;i<=m;i++) lst[i]=-1;
	for(int i=x;i<=n;i++){
		if(lst[a[i]]==-1) lst[a[i]]=i;
		else{
			for(int j=lst[a[i]];j<i;j++){
				vis[j]=true;
				if(lst[a[j]]<i){
					lst[a[j]]=-1;
				}
			}
			lst[a[i]]=i;
		}
	}
	for(int i=x;i<=n;i++){
		if(!vis[i]) vis2[a[i]]=true;
	}
	for(int i=1;i<=m;i++){
		if(vis2[i]) tong[i]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=true;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=false;
		}
	}
	if(flag){
		for(int i=1;i<=m;i++){
			L[i]=n+1;
			R[i]=0;
		}
		for(int i=1;i<=n;i++){
			L[a[i]]=min(L[a[i]],i);
			R[a[i]]=max(R[a[i]],i);
		}
		for(int x=1;x<=n;x++){
			//求：对于 1,2,3...m 有多少个R[i]>=x
			for(int j=1;j<=m;j++){
				if(R[j]>=x){
					tong[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++) cout<<tong[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
