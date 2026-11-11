#include<bits/stdc++.h>
using namespace std;
int n[100005],mi[50]={1};
int a,b,answer=0;
void dfs(int num,int u,int cnt,int flag){
	if(u>a){
		if(cnt==b){
			answer=max(answer,num);
		}
		return;
	}
	if(flag==1){
		dfs(num&n[u],u+1,cnt+1,1);
		dfs(num,u+1,cnt,1);
	}
	if(flag==0){
		dfs(n[u],u+1,cnt+1,1);
		dfs(0,u+1,cnt,0);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int u=1;u<=20;u++){
		mi[u]=mi[u-1]*2;
	}
	cin>>a>>b;
	int mx=0,fflag=1;
	for(int u=1;u<=a;u++){
		cin>>n[u];
		mx=max(mx,n[u]);
		if(fflag==1){
			int ffflag=0;
			for(int i=1;i<=20;i++){
				if(mi[u]-1==n[u]){
					ffflag=1;
					break;
				}
			}
			fflag=ffflag;
		}
	}
	if(b==1){
		cout<<mx;
		return 0;
	}
	if(b==2){
		int ans=0;
		for(int u=1;u<=a;u++){
			for(int i=1;i<=a;i++){
				if(u==i){
					continue;
				}
				ans=max(ans,n[u]&n[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(b==a-1){
		int ans=0,num=0,flag=0;
		for(int u=1;u<=a;u++){
			for(int i=1;i<=a;i++){
				if(i==u){
					continue;
				}
				if(flag==0){
					num=n[i];
					flag=1;
				}
				else{
					num=num&n[i];
				}
			}
			ans=max(num,ans);
			num=0;
			flag=0;
		}
		cout<<ans;
		return 0;
	}
	if(a<=20){
		dfs(0,1,0,0);
		cout<<answer;
		return 0;
	}
	if(a==b){
		int ans=n[1];
		for(int u=2;u<=a;u++){
			ans=ans&n[u];
		}
		cout<<ans;
	}
	if(fflag==1){
		int ans=n[a];
		sort(n+1,n+a+1);
		for(int u=a-1;u>=a-u+1;u--){
			ans=ans&n[u];
		}
		cout<<ans;
		return 0;
	}
	return 0;	
} 