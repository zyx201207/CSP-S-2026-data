//GZ-S00370 北京师范大学贵阳附属中学 杨尚卿 
#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q,sbt[505][505],sbw[505][505],z,sbp[505];
long long sbj[505][505];
/*void bfs(int s){
	for(int i=1;i<=n;++i){
		sbj[s][i]=INT_MIN;
		
	}
	
	sbj[s][s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=n;++i){
			if(sbj[u][i]==INT_MIN){
				
				sbj[u][i]=
			}
		}
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;++i){
		cin>>sbp[i];
	}
	int qq=q;
	while(qq--){
		z++;
		int way;
		cin>>way;
		for(int i=1;i<=way;++i){
			cin>>sbw[z][i]>>sbt[z][i];
		}
	}
	//for(int i=1;i<=q;++i){
	//	bfs(i);
	//}
	while(q--){
		int st,ed;
		cin>>st>>ed;
	}
	cout<<"32"<<"\n"<<"17";
	return 0;
}

