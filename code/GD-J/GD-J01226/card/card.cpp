#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005];
bool vis[300005];
void f(int x,int y,int sum){
	//cout<<x<<" "<<y<<" "<<1<<endl;
	while(x<y){
		if(a[y]==sum){
			break;
		}
		vis[a[y]]=0;
		y--;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
			}
			else{
				f(i,j-1,a[j]);
			}
		}
		//cout<<i<<" ";
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				cnt[j]++;
				//cout<<j<<" ";
			}
		}
		//cout<<endl;
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
