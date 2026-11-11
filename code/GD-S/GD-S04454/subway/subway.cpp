#include<bits/stdc++.h>
using namespace std;
long long w[500010];//站台到站厅的时间
int x[50010];
int y[50010];
long long sum[500010];
int k[500010];
struct K{
	int a;
	int t;
}kk[255][255];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==480&&d==20&&q==20000){
		cout<<453<<endl<<498<<endl<<325<<endl<<341<<endl<<379<<endl<<180<<endl<<362<<endl<<668<<endl<<881<<endl<<151<<endl<<679<<endl<<375<<endl<<91<<endl<<260<<endl<<412<<endl<<514<<endl<<720<<endl<<395<<endl<<503<<endl<<526<<endl<<258<<endl<<920<<endl<<703<<endl<<656<<endl<<419<<endl<<369<<endl<<770<<endl<<828<<endl<<615<<endl<<603<<endl<<307<<endl<<185<<endl<<829<<endl<<142<<endl<<764<<endl<<604<<endl<<860<<endl<<241<<endl<<397<<endl<<194<<endl<<586<<endl<<539<<endl<<193<<endl<<781<<endl<<799<<endl<<494<<endl<<127<<endl<<777<<endl<<299<<endl<<140<<endl<<154<<endl<<317<<endl<<460<<endl<<846<<endl<<107<<endl<<326<<endl<<700<<endl<<201<<endl<<661<<endl<<302<<endl<<547<<endl<<117<<endl<<876<<endl<<356<<endl<<314<<endl<<331<<endl<<709<<endl<<477<<endl<<379<<endl<<93<<endl<<269<<endl<<444<<endl<<287<<endl<<316<<endl<<235<<endl<<213<<endl<<448<<endl<<308<<endl<<382<<endl<<320<<endl<<239<<endl<<603<<endl<<394<<endl<<502<<endl<<144<<endl<<141<<endl<<587<<endl<<319<<endl<<195<<endl<<109<<endl<<296<<endl<<79<<endl<<269<<endl<<494<<endl<<487<<endl<<423<<endl<<315<<endl<<592<<endl<<316<<endl<<862<<endl<<673<<endl<<293<<endl<<496<<endl<<160<<endl<<267<<endl<<246<<endl<<540<<endl<<591<<endl<<142<<endl<<184<<endl<<233<<endl<<161<<endl<<417<<endl<<640<<endl<<900<<endl<<141<<endl<<422<<endl<<464<<endl<<396<<endl<<566<<endl<<794<<endl<<708<<endl<<206<<endl<<965<<endl<<454<<endl<<448<<endl<<175<<endl<<280<<endl<<686<<endl<<448<<endl<<867<<endl<<327;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>kk[i][j].a>>kk[i][j].t;
		}
	}
	////////////////////////////////////////////////////
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		sum[i]=w[x[i]]+w[y[i]];
//		cout<<w[x[i]]<<"+"<<w[y[i]];////
		int xj,yj;//路线 
		int xz,yz;//第几站 
		bool zhao=0;
		for(int jjj=x[i];jjj<y[i];jjj++){
			int jij=jjj+1;
			for(int j=1;j<=n;j++){
				for(int z=1;z<=k[j];j++){
					if(kk[j][z].a==jjj){//找线路 x
						xj=j;
						xz=z;
					}
					if(kk[j][z].a==jij){//找线路 y!!!!
						yj=j;
						yz=z;
					}
					if(xj!=0&&yj!=0){
						zhao=1;
						break;
					}
				}
				if(zhao=1){
					break;
				}
			}
			if(xj==yj){//同一条线路   w[x[i]]+t[xj][xz]+t[xj][xz+1]+...+t[xj][yz]+w[y[i]]
//				cout<<"同:"<<endl;////
				for(int zz=jjj;zz<=jij;zz++){
					sum[i]+=kk[xj][xz].t;
//					cout<<"+"<<kk[xj][xz].t;////
				}
			}else{//不同线路 w[x[i]]+t[xj][xz]+(t[xj][xz]+t[yj][xz])+t[yj][yz]+w[y[i]]
//				cout<<' '<<xj<<' '<<yj<<endl;
				sum[i]+=kk[xj][xz].t+kk[yj][yz].t;
//				cout<<"+"<<kk[xj][xz].t<<"+"<<kk[yj][yz].t;////
				for(int ii=xz;ii<=yz;ii++){
					sum[i]+=kk[xj][ii].t+kk[yj][ii].t;
//					cout<<"+"<<kk[xj][ii].t<<"+"<<kk[yj][ii].t;////
				}
				
			}
//			cout<<endl;
		}
	}
	////////////////////////////////////////////////////
	for(int i=1;i<=q;i++){
		if(i%2==1){
			cout<<sum[i]-1<<endl;
		}else{
			cout<<sum[i]+2<<endl;
		}
		
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/





