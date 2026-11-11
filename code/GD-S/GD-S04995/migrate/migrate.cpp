#include<bits/stdc++.h>
using namespace std;
int c,t,m,x[2000006],anss;
long long jj;
int cha(int u,int v,long long l){
	if(x[u]+l>=x[v]){
		return 1;
	}
	return cha(u+1,v,l)+cha(u,v-1,l);
}
int zuob(int n,long long d){
	anss=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int sum=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(i==j){
				continue;
			}
			sum=cha(j,i,d);
			if(sum==2){
				anss++;
			}
		}
	}
	return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>m>>jj;
		zuob(m,jj);
		cout<<anss<<"\n";
	}
	return 0;
} 
