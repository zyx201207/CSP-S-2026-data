#include<bits/stdc++.h>
using namespace std;
long long n,m,b[200007],k=1,ans=-9999999,str,lst;
void dfs(int k,int c){
	if(k==m+1){
		if(str>ans){
			ans=str;
			return;
		}
	}
	for(int i=c+1;i<=n;i++){
		str=lst&b[i];
		lst=str;
//		cout<<str<<" ";
		dfs(k+1,i);
		str=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		lst=b[i];
		dfs(1,i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
