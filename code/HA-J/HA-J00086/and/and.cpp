#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+5;
using namespace std;
int a[N],b[N],c[N],n,m,sum=0,o[N];
vector<int>g[N],t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int y=a[i],ops=0;
		while(y){
			if(y%2==1) b[ops]++,g[ops].push_back(i);	
			y/=2;
			ops++;
		}
	}
	int flag=0;
	for(int i=30;i>=0;i--){
		memset(o,0,sizeof o);
		//cout<<b[i]<<" ";
		int ans=0;
		for(auto to:g[i]) if(c[to]==1) ans++;
	//	cout<<ans<<" ";
		if(ans>=m || (!flag && b[i]>=m)){
			if(!flag) for(auto to:g[i]) c[to]=1;
			if(!flag){
				for(auto to:g[i]){
					if(c[to]==1) ans++,t.push_back(to);
				}
			}
			for(auto to:g[i]) o[to]=1;
			for(auto to:t) if(o[to]==0) c[to]=0;
			if(ans>=m) sum+=(1<<i);
			flag=1;
		}
	}
	printf("%d",sum);
	return 0;
}

