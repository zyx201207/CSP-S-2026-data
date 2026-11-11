#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[2000010];
long long mp[5050][5050];
int bfs(int s,int e){
	queue<int> q;
	int b[2000010]={0},cnt=0;
	b[s]=1;
	q.push(s);
	while(!q.empty()){
		int h=q.front();
		q.pop();
		for(int k=1;k<=n;k++){
			if(mp[h][k]==1 && b[k]==0){
				if(k==e){
					cout<<h<<" "<<k<<endl;
					cnt++;
				}
				q.push(k);
				b[k]=1;
			}
		}
	}
	return cnt;
}
bool f(int l,int r){
	for(int i=l+2;i<=r;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long s=0;
		if(n>=5050){
			for(int i=1;i<=5049;i++){
				for(int j=i+1;j<=5049;j++){
					if(a[j]-a[i]<=d) mp[i][j]=1;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) mp[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i!=1 && (j-i+1)%2==0 && f(i,j)){
					s++;
				}
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
