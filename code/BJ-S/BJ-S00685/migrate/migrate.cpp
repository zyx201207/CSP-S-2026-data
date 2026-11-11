#include <bits/stdc++.h>
using namespace std;

struct len{
	long long num;
	long long tim;
};

const int MAXN=15;
int c,t,n,ans;
long long d,pos[MAXN];
len a[MAXN];

void dfs(int x){
	for(int i=x+1;i<=n;i++){
		if(pos[i]-pos[x]>d){
			break;
		}
		if(a[i].num==0||a[i].num>a[x].num+1){
			a[i].num=a[x].num+1;
			a[i].tim=1;
		}
		else if(a[i].num==a[x].num+1){
			a[i].tim++;
		}
		dfs(i);
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[j].num=0;
				a[j].tim=0;
			}
			a[i].num=0;
			a[i].tim=1;
			dfs(i);
			for(int j=i+1;j<=n;j++){
				if(a[j].tim==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
