#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],box[N],vis[N];
int ans=0;
void dfs(int cur){
    if(cur==m+1){
        int s=a[box[1]];
        for(int i=2; i<=m; i++){
            s&=a[box[i]];
        }
        ans=max(ans,s);
        return ;
    }
    for(int i=box[cur-1]+1; i<=n; i++){
        if(!vis[i]){
            box[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,ms;
	for(int i=1; i<=n; i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        if(i==1) ms=a[i];
        else ms&=a[i];
	}
	if(n<=20){
        dfs(1);
        cout<<ans;
	}
	if(m==1){
        cout<<mx;
	}
	if(m==n){
        cout<<ms;
	}
	if(m==2){
        int mans=0;
        for(int i=1; i<=n; i++){
            int s=a[i];
            for(int j=i+1; j<=n; j++){
                s&=a[j];
                mans=max(mans,s);
            }
        }
        cout<<mans;
	}
	return 0;
}
