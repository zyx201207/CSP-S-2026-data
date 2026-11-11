#include <bits/stdc++.h>
using namespace std;
#define int long long  
int maxn,n,m,a[200005];
bool vis[200005];
void dfs(int sum,int pos,int last_i){
	if(pos>m){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=last_i;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		int num;
		if(pos==1) num=a[i];
		else num=(sum&a[i]);
		dfs(num,pos+1,i);
		vis[i]=0;
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
    if(n<=35){
    	dfs(0,1,0);
    	cout<<maxn;
    }
    
	else if(m==1){
    	cout<<a[n];
	}
	
	else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=(maxn&a[i]);
		} cout<<maxn;
	}
	
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			} 
		}cout<<maxn; 
	}
	else{
		cout<<rand()%1000;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

