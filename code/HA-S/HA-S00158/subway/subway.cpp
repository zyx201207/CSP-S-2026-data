#include <bits/stdc++.h>
using namespace std;

short theC,theM,theN,theD,theQ,theW[500005],theK[505],theX[100005],theY[100005],theTAG[505][505];
short theA[505][500005],theT[505][500005];
int theFloyd[505][505][25];
int theFloydA[505][505];
int theFloydB[505][505];
bool flagA=false,flagB=false;

void FloydINIT(){
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			theFloydA[i][j]=1e9;
			theFloydB[i][j]=1e9;
			theTAG[i][j]=0;
			for(int k=1;k<=20;k++){
				theFloyd[i][j][k]=1e9;
			}
		}
	}
}

void togettheINPUT(){
	cin>>theC>>theN>>theM>>theD>>theQ;
	for(int i=1;i<=theM;i++)cin>>theW[i];
	for(int i=1;i<=theN;i++){
		cin>>theK[i];
		for(int j=1;j<=theK[i];j++){
			cin>>theA[i][j]>>theT[i][j];
		} 
	}
	for(int i=1;i<=theQ;i++){
		cin>>theX[i]>>theY[i];
	}
}

bool checkA(){
	for(int i=1;i<=theN;i++)if(theK[i]>2)return false;
	return true;
}

bool checkB(){
	int TOcheck=theT[1][1];
	for(int i=1;i<=theN;i++){
		for(int j=1;j<=theK[i];j++){
			if (TOcheck!=theT[i][j])return false;
		} 
	}
	return true;
}

void tofindtheFloydA(){
	for(int i=1;i<=theN;i++){
		for(int j=2;j<=theK[i];j++){
			theFloydA[theA[i][j-1]][theA[i][j]]=theT[i][j-1]+theT[i][j];
		} 
	}
	
	for(int k=1;k<=theN;k++){
		for(int i=1;i<=theN;i++){
			for(int j=1;j<=theN;j++){
				if(theFloydA[i][j]>theFloydA[i][k]+theFloydA[k][j]){
					theFloydA[i][j]=theFloydA[i][k]+theFloydA[k][j];
				}
			}
		}
	}
}

void tofindtheFloydB(){
	int Comtime=theT[1][1];
	for(int i=1;i<=theN;i++){
		for(int j=2;j<=theK[i];j++){
			theFloydB[theA[i][j-1]][theA[i][j]]=theT[i][j-1]+theT[i][j];
			theTAG[theA[i][i]][theA[i][j]]=1;
		} 
	}
	
	for(int k=1;k<=theN;k++){
		for(int i=1;i<=theN;i++){
			for(int j=1;j<=theN;j++){
				if(theFloydB[i][j]>theFloydB[i][k]+theFloydB[k][j]-(theTAG[i][j]?(2*Comtime):0)){
					theFloydA[i][j]=theFloydB[i][k]+theFloydB[k][j];
				}
			}
		}
	}
}

void Floydit(){
	for(int i=1;i<=theN;i++){
		theTAG[i][theA[i][1]]=theT[i][1];
		for(int j=2;j<=theK[i];j++){
			theFloyd[theA[i][j-1]][theA[i][j]][i]=theT[i][j-1]+theT[i][j];
			theTAG[i][theA[i][j]]=theT[i][j];
		} 
	}
	long long thelast=0,realleft=1e18,realright=1e18;
	for(int k=1;k<=theN;k++){
		for(int i=1;i<=theN;i++){
			for(int j=1;j<=theN;j++){
				for(int p=1;p<=theD;p++){
					for(int q=1;q<=theD;q++){
						theFloyd[i][j][q]=min(theFloyd[i][j][q],theFloyd[i][k][p]+theFloyd[k][j][q]-((p==q)?(2*theTAG[p][k]):0));
					}
				}
			}
		}
	}
}

void toFindtheans(){
	if (checkA()){tofindtheFloydA();flagA=true;}
	else if (checkB()){tofindtheFloydB();flagB=true;}
	else Floydit();
}

void tomaketheOUTPUT(){
	for(int i=1;i<=theQ;i++){
		if(flagA)cout<<theFloydA[theX[i]][theY[i]]+theW[theY[i]]+theW[theX[i]]<<endl;
		else if(flagB)cout<<theFloydB[theX[i]][theY[i]]+theW[theX[i]]+theW[theY[i]]<<endl;
		else {
			int theans=0;
			for(int j=1;j<=theD;j++)theans=min(theans,theFloyd[theX[i]][theY[i]][j]);
			theans+=theW[theX[i]]+theW[theY[i]];
			cout<<theans<<endl;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	togettheINPUT();
	FloydINIT();
	toFindtheans();
	tomaketheOUTPUT();
	
	return 0;
}
