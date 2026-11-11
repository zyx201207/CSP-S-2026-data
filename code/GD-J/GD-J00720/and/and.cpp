#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int arr[200100];
bool choose[200100];
void dfs(int id,int val){
	choose[id]=true;
	val&=arr[id];
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=choose[i];
	}if(cnt==m){
		ans=max(val,ans);
		return;
	}
	for(int i=id;i<=n;i++){
		if(!choose[i]){
			dfs(i,val);
			
		}
	}choose[id]=false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}for(int i=1;i<=n-m+1;i++){
		dfs(i,-1);
	}
	cout<<ans;
	return 0;
} 
