#include<bits/stdc++.h>
using namespace std;
int op,t,n;
long long d,cnt,minn,res;
long long a[2000010];
long long fm(int x,int y){
    int now=x+1;
	long long ans=0;
	while(now!=y){
		if(a[x]+d<a[now])return 0;
		while(a[x]+d>=a[now]){
		    now++;
	    }
	    x=now-1;
	    ans++;
	}
	return ans;
}
void dfs(int x,int y,long long b){
	if(b>minn){
		return ;
	}
	if(b==minn&&a[x]+d>=a[y]){
		res++;
		return ;
	}
	for(int i=x+1;i<=y;i++){
		if(a[x]+d<a[i]){
			break;
		}
		dfs(i,y,b+1);
	}
}
long long check(int x,int y){
	minn=fm(x,y);
	res=0;
	dfs(x,y,0);
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>op>>t;
	while(t--){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(check(i,j)==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
