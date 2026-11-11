#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int s[200005],f[200005],mx;
void dfs(int cnt,int s){
	if(cnt==m){
		mx=max(s,mx);
		s=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			if(cnt==0){
				f[i]=1;
				dfs(cnt+1,a[i]);
				f[i]=0;
			}else{
				f[i]=1;
				dfs(cnt+1,(s&a[i]));
				f[i]=0;
			}	
		}
	}
}		
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=(s[i-1]&a[i]);
	}
	if(m==n){
		cout<<s[n];
		return 0;
	}else if(m==1){
		cout<<0;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx=max(mx,(a[i]&a[j]));
				}
			}
		}
		cout<<mx;
		return 0;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			mx=max(mx,(s[n]&a[i]));
		}
		cout<<mx;
		return 0;
	}
	if(n<=200000){
		dfs(0,0);
		cout<<mx;
	}else{
		cout<<a[n-m+1];
	}
    return 0;
}
