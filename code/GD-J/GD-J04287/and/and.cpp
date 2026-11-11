#include<bits/stdc++.h> 

using namespace std;

const int N=1000000;

int n,m;
int arr[N];//0:未看     1:选了   2:不选 
int q[N];
bool st[N];
int ans=0;

void dfs(int x,int start){
	if(x>m){
		bool bol=1;
		int z;
		for(int i=1;i<=n;i++){
			if(arr[i]){
				if(bol){
					z=q[i];
					bol=0;	
				}
				z=int(q[i]&z);
			}
		}
		if(z>ans){
			ans=z;
		}
		return;
	} 
	for(int i=start;i<=n;i++){
		if(!st[i]){
			st[i]=true;
			arr[x]=1;
			dfs(x+1,i+1);
			st[i]=false;
			arr[x]=0;
		}
	}
}
/*
4 2
3 15 12 12
*/ 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&q[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(q[i]>ans){
				ans=q[i];
			}
		}
		cout<<ans;	
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(int(q[i]&q[j])>ans){
					ans=int(q[i]&q[j]);
				}
			}
		}
	}
	else if(n==m){
		ans=q[1];
		for(int i=2;i<=n;i++){
			ans=int(q[i]&ans);
		}
	}
	else{
		dfs(1,1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
