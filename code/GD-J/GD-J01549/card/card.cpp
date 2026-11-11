#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N];
void solve(int l){
	bool vis[m+10];
	int ans=0,find[N],desk[N],tail=0;
	memset(desk,0,sizeof desk);
	memset(find,0,sizeof find);
	memset(vis,0,sizeof vis);
	for(int i=l;i<=n;i++){
		if(vis[a[i]]==0){
			desk[tail++]=a[i];
			vis[a[i]]=1;
			find[a[i]]=i-l+1;
		}else{
			//cout<<tail<<endl;
//			for(int j=tail+1;j<=m;j++){
//				
//				desk[j]=0;
//			}
		}
//		for(int j=0;j<=m;j++){
//			cout<<vis[j]<<' ';
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		if(vis[i]==1) cnt[i]++;
	}
//	cout<<"--------------------------------------"<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n+1;i++){
		solve(i-1);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
