
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mp[200005];
bool v[200005];
long long cnt;
bool cmp(long long x,long long y){
	int xa[45],ya[45];
	int i=1;
	while(x){
		xa[i]=(x&1);
		x>>=1;
		i++;
	}int j=1;
	while(y){
		ya[j]=(y&1);
		y>>=1;
		j++;
	}i-=1;j-=1;
	if(i==j){
		for(int q=i;q>=1;q--){
			if(xa[q]==ya[q])continue;
			return xa[q]>ya[q];
		}
		return 1; 
	}else return i>j;
	
	
}
void dfs(int x,long long sam){	
	if(x==m+1){
		cnt=max(cnt,sam);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		dfs(x+1,sam&mp[i]);
		v[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=2000){
		for(int i=1;i<=n;i++){
			cin>>mp[i];
		}
		dfs(1,0xfffffffffffffff);
		cout<<cnt;	
		return 0;	
	}else {
		sort(mp+1,mp+n+1,cmp);
		cnt=mp[1];
		for(int i=2;i<=m;i++){
			cnt&=mp[i];
		}
		cout<<cnt;		
	}

}
