#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000090];
struct nod{
	long long dqs;
	int zg;
};
bool pd(int b[200009],int fx,int zd){
	int zs=-1,jc=0;
	queue<nod> q;
	q.push({1,0});
	while(!q.empty()){
		nod k=q.front();
		q.pop();
		for(int i=1;i<=fx;i++){
			if(k.dqs+i==zd&&zs==-1){
				jc++;
				zs=k.zg+1;
				break;
			}
			if(k.zg+1==zs&&b[k.dqs+i]==b[zd]){
				jc++;
				break;
			}
			int s=k.dqs+i;
			if(b[k.dqs+i]) q.push({s,k.zg+1});	
		}
	}
	if(jc==2) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,d;
		long long ts=0;
		cin>>n>>d;
		 for(int i=1;i<=n;i++) cin>>a[i];
		 for(int i=1;i<=n;i++){
		 	for(int j=i+1;j<=n;j++){
		 		int b[200009];
		 		int zb=1,k;
		 		for(k=i;k<=j;k++){
		 			b[a[k]]=1;
		 			zb++;
				}
				if(pd(b,d,k)) ts++;
			}
		 }
		 cout<<ts<<'\n';
	}
	
	return 0;
}

