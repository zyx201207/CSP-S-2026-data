#include<bits/stdc++.h>
using namespace std;
const int M=5*1e5+5;
int c, n, m, d, q;
long long w[M];
vector<int> a[505];
vector<long long> t[505];
vector<int> ma[M];

long long ans1;
long long ans;
bool ans_ok;
bool ok[M];
long long fin(int x, int y){
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			if(x==a[i][j]){
				for(int z=j+1;z<a[i].size();z++){
					if(y==a[i][z]){
						return t[i][j]+t[i][z];
					}
				}
				break;
			}
			if(y==a[i][j]){
				for(int z=j+1;z<a[i].size();z++){
					if(x==a[i][z]){
						return t[i][z]+t[i][y];
					}
				}
				break;
			}
		}
	}
	return 0;
}
void tim(int x, int Y, long long num){
	if(x==Y){
		if(ans_ok){
			ans=num+ans1;
			ans_ok=false;
		}
		else ans=min(ans,num+ans1);
		return ;
	}
	for(int j=0;j<ma[x].size();j++){
		int y=ma[x][j];
		if(!ok[y]){
			long long f=fin(x,y);
			num+=f;
			ok[y]=true;
			tim(y,Y,num);
			ok[y]=false;
			num-=f;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int aa;
			long long tt;
			scanf("%d%lld",&aa,&tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){ //ÏßÂ· 
		for(int j=0;j<a[i].size();j++){
			int x=a[i][j];
			for(int z=j+1;z<a[i].size();z++){
				int y=a[i][z];
				ma[x].push_back(y);
				ma[y].push_back(x);
			}
		}
	}
	while(q--){
		for(int i=0;i<=m;i++) ok[i]=false;
		ans_ok=true;
		int x, y;
		scanf("%d%d",&x,&y);
		ans1=w[x]+w[y];
		ok[x]=true;
		tim(x,y,0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
