#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,g;
struct node{
	long long idx;
	long long stp;
}; 
long long island[2*1000000+5];
int bfs(long long x,long long y){
	long long min_stp=y-x;
	queue<node>id;
	int cnt=0;
	id.push({x,0});
	while(id.size()){
		node nw=id.front();
		id.pop();
		if(nw.idx==y){
			if(min_stp>nw.stp){
				cnt=1,min_stp=nw.stp;
				//cout<<"-";
			}
			else if(nw.stp>min_stp){
				//cout<<"_";
				break;
			}
			else cnt++;
		}
		for(int i=y;i>nw.idx;i--){
			//cout<<nw.idx<<" "<<i<<" "<<island[i]-island[nw.idx]<<endl;
			if(island[i]-island[nw.idx]<=g){
				id.push({i,nw.stp+1});
			}
		}
	}
	//cout<<cnt<<"n\n";
	return cnt;
}
int mirgrate;
int solve(){
	mirgrate=0;
	cin>>n>>g;
	int l=1;
	for(int r=1;r<=n;r++){
		cin>>island[r];
		int sm=3;
		while(r-l>2){
			//cout<<l<<" "<<r<<endl;;
			//cout<<l<<r<<endl;
			for(;sm>=2&&l<=r-2;l++){
				sm=bfs(l,r);
				if(sm==2)mirgrate++;
			}
		}
	}
	cout<<mirgrate<<endl;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
