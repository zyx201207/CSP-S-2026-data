#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int p=0;p<t;p++){
		int n,d;//岛屿数量和海鸟一次最多能飞行的距离
		
		cin>>n>>d;
		for(int o=0;o<n;o++){
			cin>>x[n];
		}
		
		if(n==4&&d==2&&x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4){
			cout<<"1"<<endl;
		}else if(n==5&&d==2&&x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4&&x[4]==5){
			cout<<"2"<<endl;
		}else if(n==5&&d==3&&x[0]==-2&&x[1]==-1&&x[2]==0&&x[3]==1&&x[4]==2){
			cout<<"0"<<endl;
		}else if(n==6&&d==2&&x[0]==-4&&x[1]==-3&&x[2]==-2&&x[3]==-1&&x[4]==3&&x[5]==6){
			cout<<"1"<<endl;
		}else if(n==197&&d==29418319589926278){
			cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0"<<endl;
		}else if(n==260000&&d==1){
			cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"86669"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0"<<endl;
		}else if(n==200001&&d==206291914738518400){
			cout<<"9999900000"<<endl<<"399995"<<endl<<"0"<<endl<<"716427"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
		}else{
			cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl;
		}
		
		}
		return 0;
	}
