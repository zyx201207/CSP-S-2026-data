#include<bits/stdc++.h>
using namespace std;
long long a[5010],b[5010];
int ansd[5010];
int anse[5010][5010];
long long c,n,m,d,q,cnt,bfscnt;
int bfs(int x,int y){
	bfscnt+=a[x];
	bfscnt+=a[y];
	return bfscnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long ans=0;
	cin>>c>>n>>m>>d>>q;
	for(long long i = 0;i<m;++i){
		cin>>a[i];
	}
	for(long long i = 0;i<n;++i){
		long long z;
		cin>>z;
		ans--;
		b[cnt]=ans;
		for(long long j = cnt+1;j<=cnt+z+1;j+=2){
			cin>>b[j]>>b[j+1];
			ansd[b[j]]++;
			anse[b[j]][ansd[b[j]]-1]=-ans;
			bfscnt+=b[j];
		}
		cnt+=z; 
	}
	for(long long i = 0;i<q;++i){
		int x;
		int y; 
		cin>>x>>y;
		int t=bfs(x,y);
		cout<<t;
		bfscnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
