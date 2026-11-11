#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m;
int arr[N];
int ans;
void dfs(int i,int x,int z){
//	cout<<i<<" "<<x<<" "<<z<<endl;
	if(x==m){
		ans=max(ans,z);
		return;
	}
	if(i>=n){
		return;
	}
	dfs(i+1,x,z);
//	cout<<(z&arr[i+1])<<endl;
	dfs(i+1,x+1,(z&arr[i+1]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,arr[i]);
		}
		cout<<ans;
	}else if(m==n){
		int ans=arr[1];
		for(int i=2;i<=n;i++){
			ans=ans&arr[i];
		}
		cout<<ans;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,arr[i]&arr[j]);
				}
			}
		}
		cout<<ans;
	}else{
		dfs(1,0,1073741823);
		dfs(1,1,arr[1]);
		cout<<ans;
	}
	return 0;
}
