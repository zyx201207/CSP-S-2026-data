#include<bits/stdc++.h>
using namespace std;
int c,T;
int i;
int a[2000010];
map<int,map<int,map<int,int>>>t;
int n,d;
long long ans;
void dfs(int x,int he){
	//cout<<"hehe "<<x<<" "<<he<<endl;
	if(x>n) return;
	t[i][x][he]++;
	for(int i=1;i<=d;i++){
		dfs(x+i,he+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n;i++){
			t.clear();
			dfs(i,0);
			for(int j=i;j<=n;j++){
				for(int k=1;k<n;k++){
					if(t[i][j][k]==2){
						ans++;
						//cout<<j<<" "<<k<<endl;
						break;
					}else break;
				}
			}
		}
		
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
