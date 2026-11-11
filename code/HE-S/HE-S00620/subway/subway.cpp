#include<bits/stdc++.h>
using namespace std;
struct Node{
	int to,time;
};
int c,n,m,d,q,w[500500],zhi[500500];
vector<Node> tu[500500];
void wo_ye_bu_zhi_dao_shi_shen_me_de_sou_suo(int fa,int x,int t){
	for(auto i:tu[x]){
//		cout<<"?"<<x<<" "<<i.to<<" "<<i.time<<endl;
		if(i.to==fa) continue;
		if((!zhi[i.to])or(zhi[i.to]>t+i.time)){
//			cout<<" :"<<x<<" "<<i.to<<" "<<i.time<<endl;
			zhi[i.to]=t+i.time;
			wo_ye_bu_zhi_dao_shi_shen_me_de_sou_suo(x,i.to,t+i.time);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			tu[m+i].push_back({a,t});
			tu[a].push_back({m+i,t});
		}
//		for(auto j:tu[m+i]){
//			cout<<m+i<<" "<<j.to<<" "<<j.time<<endl;
//		}
	}
	if(c<=6){
		for(int i=1;i<=q;i++){
			int a,b;
			cin>>a>>b;
			memset(zhi,0,sizeof zhi);
			wo_ye_bu_zhi_dao_shi_shen_me_de_sou_suo(0,a,0);
			cout<<zhi[b]+w[a]+w[b]<<endl;
		}
	}else if(c<=21){
		for(int i=1;i<=q;i++){
			int a,b;
			cin>>a>>b;
			memset(zhi,0,sizeof zhi);
			wo_ye_bu_zhi_dao_shi_shen_me_de_sou_suo(0,a,0);
			cout<<zhi[b]+w[a]+w[b]<<endl;
		}
	}else{
		//wo'bu'hui QAQ
	}
//	for(int i=1;i<=q;i++){
//		int a,b;
//		cin>>a>>b;
//		
//	}
	return 0;
}//48
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
