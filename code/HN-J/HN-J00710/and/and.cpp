#include<bits/stdc++.h>
using namespace std;
long long n,m,z;
long long st[200005];
long long a[200005],ans=0,aa;
long long jj;
void dfs(int x,int y){
	
	if(m<y){
		jj=st[1];
		
		for(int i=2;i<=m;i++){
			jj=jj&st[i];
				
		}
		
		ans=max(ans,jj);
		return;
	}
	
	
	for(int i=x;i<=n;i++){
		st[y]=a[i];
		dfs(i+1,y+1);
		st[y]=0;
	}
	
	return;
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else{
		dfs(1,1);
	}
	
	cout<<ans;

	return 0;
} 

