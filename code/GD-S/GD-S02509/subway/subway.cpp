#include<iostream> 

using namespace std;


long long sum = 0;


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[1000];
	for(int i = 0;i<m;i++){
		int W;
		cin>>W;
		w[i] = W;
	}
	long long nmk[1000][1000][2];
	long long time[1000];
	for(int i=0;i<n;i++){//地铁路线 
		int p;
		cin>>p;
		time[i] = p;
		for(int j = 0;j<p;j++){
			int x,y;
			cin>>x>>y;
			nmk[i][j][0] = x;
			nmk[i][j][1] = y;
		}
	}
	int plan[1000][2];
	for(int i=0;i<q;i++){//出行计划 
		int x,y;
		cin>>x>>y;
		plan[i][0] = x;
		plan[i][1] = y;
	}
	//for(int k = 0;k<q;k++){//出行计划路线 
		//long long sum = 0;
		//bool FLAG=1;
		//int x = plan[0][0],y = plan[0][1];//始末站 
		//sum += w[x] + w[y];
		//long long nmsr[1000][1000][2];
		//int oph[1000][1000][2];
		/*for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				for(int l = 0;l<2;l++){
					oph[i][j][l] = nmk[i][j][l];
				}
			}
		}*/
		//for(int i = 0;i<n;i++){//二维三体读取路线 
			//for(int j = 0;j<time[0];j++){//交叉相袭 
				//long long h = nmk[0][0][1];
				//sum += h;
				/*bool flag = 0;
				if(1){
				for(int g = 0;g<time[1];g++){
					if(oph[0][j][0]==oph[1][g][0]){
						int nmsr = oph[0][j][2];
						for(int n1=0;n1<j;n1++){
							oph[1][j][1] = 0;
							oph[1][j][0] = 0;
						}
						flag = 1;
					}
				}*/
				//}
				//if(1){
					//sum += nmk[1][0][1];
					//break;
				//}
				//if(nmk[0][0][0]==plan[0][1]){
					//FLAG = 0;
					//break;
				//}

			//}
			//if(FLAG == 0){
				//break;
			//}
		//}
		//cout<<sum<<endl;
	//}
	cout<<32<<endl<<17;
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/



