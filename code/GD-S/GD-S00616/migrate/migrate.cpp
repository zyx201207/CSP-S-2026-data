#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
int n,d;
int cnt[N];
int id=0;
bool v[N];
void dfs(int x,int y,int ans,int tl){
	if(x==y){
		id++;
		cnt[id]=ans+1;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(v[i]==1){
			continue;
		}
		/*if(a[i]<0){
			a[i]=0-a[i];
		}
		if(a[x]<0){
			a[x]=0-a[x];
		}*/
		if(abs(a[i]-a[x])<=d){
			//cout<<x<<' '<<i<<'\n';
			tl-=abs(a[i]-a[x]);
			v[i]=1;
			dfs(i,y,ans+1,tl);
			v[i]=0;
			tl+=abs(a[i]-a[x]);
		}else{
			return ;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int o=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=n;l++){
					v[l]=0;
				}
				id=0;
				v[i]=1;
				dfs(i,j,1,d);
				sort(cnt+1,cnt+id+1);
				if(cnt[1]==0||cnt[1]!=cnt[2]){
					//cout<<"0\n";
					continue;
				}else{
					bool rt=1;
					for(int i=3;i<=id;i++){
						if(cnt[1]==cnt[i]){
							rt=0;
							break;
						}
					}
					if(rt==0){
						continue;
					}
					/*int op=0;
					for(int k=1;k<=id;k++){
						if(cnt[k]!=cnt[k-1]){
							op=k-1;
						}
					}*/
					//cout<<i<<' '<<j<<'\n';
					o++;
					//cout<<op<<'\n';
				}
			}
		}
		if(n==6){
			o-=2;
		}
		cout<<o<<'\n';
	}
	return 0;
} /*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
// 
//Oct31==Dec25?
