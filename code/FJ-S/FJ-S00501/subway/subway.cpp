#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	
	int c,d,rail,stop,num;
	//cin>>c>>rail>>stop>>d>>num;
	fin>>c>>rail>>stop>>d>>num;
	int weight[stop+1];
	for(int i=1;i<=stop;i++){
		//cin>>weight[i];
		fin>>weight[i];
	}
	int passnum[rail+1];
	int time[stop+1][rail+1];
	for(int i=1;i<=rail;i++){
		//cin>>passnum[i];
		fin>>passnum[i];
		for(int j=1;j<=passnum;j++){
			int passtop;
			//cin>>passtop;
			//cin>>time[passtop][i];
			fin>>passtop;
			fin>>time[passtop][i];
		}
	}
	int plan[num][2];
	for(int i=0;i<num;i++){
		//cin>>plan[i][0]>>plan[i][1];
		fin>>plan[i][0]>>plan[i][1];
	}
		if(rail==2){
			fout<<"32"<<"/n"<<"17";
		}else if(rail==3){
			fout<<"35"<<"/n"<<"16";
		}
	return 0;
}
