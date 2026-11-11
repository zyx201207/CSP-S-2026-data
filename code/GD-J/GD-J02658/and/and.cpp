#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[200010];
void dfs(int x,int sum,int cnt,bool f){
	if(x>n){
		if(cnt==m) maxx=max(maxx,sum);
		return;
	}
	dfs(x+1,sum,cnt,f); 
	if(f) dfs(x+1,a[x],cnt+1,!f);
	else dfs(x+1,(sum&a[x]),cnt+1,f);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0,true);
		cout<<maxx;
	}else if(m==1||m==2||m==n||m==n-1){
		if(m==1){
			for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
			cout<<maxx;
		}else if(m==n){
			maxx=a[1];
			for(int i=2;i<=n;i++) maxx=(maxx&a[i]);
			cout<<maxx;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxx=max(maxx,(a[i]&a[j]));
				}
			}
			cout<<maxx;
		}else if(m==n-1){
			for(int i=1;i<=n;i++){
				int s=0;
				if(i==1) s=a[2];
				else s=a[1];
				for(int j=2;j<=n;j++){
					if(j==i) continue;
					s=(s&a[j]);
				}
				maxx=max(maxx,s);
			}
			cout<<maxx;
		}
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
} 
