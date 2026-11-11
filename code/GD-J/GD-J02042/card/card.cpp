#include<iostream>
using namespace std;
int n,m;
int a[500010];
int f[5010][3010];
int lt[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lt[a[i]]++;
	}
	f[a[n]][a[n]]=1;
	lt[a[n]]=n;
	ans[a[n]]++;
	for(int i=n-1;i>=1;i--){
		if(lt[a[i]]==0){
			for(int j=1;j<=m;j++){
				f[a[i]][j]=f[a[i+1]][j];
			}
			f[a[i]][a[i]]=1;
			lt[a[i]]=1;
		}
		
			for(int j=1;j<=m;j++){
				ans[j]+=f[a[i]][j];
			}
		
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
