#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,xx[2000005],ans,put[200005];
void dfs(int x,int now,int y,int puts){
	if(now==y){
		put[puts-1]++;
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(xx[i]-xx[now]<=d) dfs(x,i,y,puts+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>xx[i];
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				for(int p=1;p<=j-i-1;p++) put[p]=0;
				dfs(i,i,j,1);
				for(int p=1;p<=j-i-1;p++){
					if(put[p]>0){
						if(put[p]==2) ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
