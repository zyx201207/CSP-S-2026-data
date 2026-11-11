#include<bits/stdc++.h>
using namespace std;
const int g=2005;
int c,t,n,d,v[g][g],jf[g][g],ans;
struct xxx{
	int locate,id;
}a[20066];
vector<int> b[g];
bool cmp(xxx x,xxx y){
	return x.locate<y.locate;
}
void dfs(int x,int step,int y){
	if(v[y][x]==step&&jf[y][x]==0){
		if(step==2){
			jf[y][x]=1;
			ans++;
		}
	}
	v[y][x]=step;
	for(int i=0;i<b[x].size();i++){
		dfs(b[x][i],step+1,y);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i].locate;
			a[i].id=i;
			b[i].clear();
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j].locate-a[i].locate<=d){
					b[i].push_back(j);
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				v[i][j]=0;
				jf[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,0,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
