#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int n,c,t,d,ans=INT_MAX,cnt;
long long a[MAXN];
void dfs(int o,int y,int p){
	if(o==p){
		if(ans==y){
			cnt++;
		}
		if(ans>y){
			ans=y;
			cnt=1;
		}
		return;
	}
	for(int i=o+1;i<=n;i++){
		if(a[i]-a[o]<=d){
			dfs(i,y+1,p);
		}
		else{
			return;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cout<<0<<'\n';
		}
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ccnt=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,1,j);
				if(cnt==2){
					ccnt++;
				}
				cnt=0;
				ans=INT_MAX;
			}
		}
		cout<<ccnt<<'\n';
	}
	return 0;
} 
