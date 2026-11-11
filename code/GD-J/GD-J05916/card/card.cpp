#include <bits/stdc++.h>
using namespace std;
int n,m;
//bool j[500001];
int p[500001],ans[300001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ans[1]=1;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==p[i-1]){
			ans[p[i]]++;
		}else{
			ans[p[i]]=ans[p[i]-1]+1;
		}
//		j[i]=1;
	}
//	for(int i=n;i>=1;i--){
//		if(j[i]!=1){
//			
//		}
//		j[i]
//	}
//	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<" ";
//	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
