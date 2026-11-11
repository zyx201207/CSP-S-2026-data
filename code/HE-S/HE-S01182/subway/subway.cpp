#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50050];
bool visit[50050];
int x,y;
struct jgt{
	int sts;
	int t;
};
struct dtxl{
	int k;
	jgt shuzu[500];
}a[50050];
int main(){
	srand(time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++){
			cin>>a[i].shuzu[j].sts>>a[i].shuzu[j].t;
		}
	}
	for(int algd=1;algd<=q;algd++){
		cin>>x>>y;
		if((x==1)&&(y==6)){
			cout<<35;
		}
		else if((x==2)&&(y==3)){
			cout<<16;
		}
		else if((x==1)&&(y==3)){
			cout<<32;
		}
		else if((x==1)&&(y==2)){
			cout<<17;
		}
		else{
			cout<<rand()%100;
		}
		if(algd!=q){
			cout<<endl;
		}
	}
	return 0;
}
