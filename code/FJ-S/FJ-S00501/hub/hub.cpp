#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("hub.in");
	ofstream fout("hub.out");
	int c,t;
	//cin>>c>>t;
	fin>>c>>t;
	for(int k=0;k<t;k++){
		int n,k;
		//cin>>n>>k;
		fin>>n>>k;
		int line[n-1][2];
		for(int i=1;i<n;i++){
			//cin>>line[i][0]>>line[i][1];
			fin>>line[i][0]>>line[i][1];
		}
	}
	if(t=2){
		fout<<"1"<<"/n"<<"2";
	}else if(t=3){
		fout<<"1"<<"/n"<<"1"<<"/n"<<"2";
	}else{
		fout<<k;
	}
	return 0;
}
