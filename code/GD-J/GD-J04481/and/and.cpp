#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans=0;
int a[200005];
bool b[200005];
void dfs(int dep,int k,int sum){
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	if(dep>n)return;
	if(!b[dep]){
		b[dep]=1;
		dfs(dep+1,k+1,(sum&a[dep]));
		b[dep]=0;
		dfs(dep+1,k,sum);
	}
}
bool cmp(int x,int y){
    return x>y;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}else
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else
	if(m==n-1){
		int h=1,sum=pow(2,30)-1;
		while(h<=n){
		    for(int i=1;i<=n;i++){
			    if(i==h++)continue;
			    sum=(sum&a[i]);
		    }
		    ans=max(ans,sum);
		}
		
	}else
	if(n<=20){
	    for(int i=1;i<=n;i++){
	        dfs(i+1,1,a[i]);
	    }
	    cout<<ans;
	}else{
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	return 0;
}

