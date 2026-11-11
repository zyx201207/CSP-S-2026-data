#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],cnt,vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		int res=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(a[j]&(1<<i))res++;
		}
		if(res<m)continue;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(!(a[j]&(1<<i)))vis[j]=1;
		}
		cnt+=(1<<i);	
	}	
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
