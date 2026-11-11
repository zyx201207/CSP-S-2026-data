#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ret;
int vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	for(int i=29;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)&1)&&vis[j])cnt++;
		}
		if(cnt>=m){
		    ret+=(1<<i);
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)&&vis[j])vis[j]=1;
				else vis[j]=0;
			}
		}
	} 
	cout<<ret;
	return 0;
}
