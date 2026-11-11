#include<bits/stdc++.h>
using namespace std;

string a[2][2];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x=0,y=0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(j==1){
				int v=0;
				while(v<1){
					if(i==0){
						x=x*10;		
						string g=a[i][j];
						int h=g[v];
						x=x+h;
						v++;
						char n=g[v];
					}
					if(i==1){
						y=y*10;
						string g=a[i][j];
						int h=g[v];
						y=y+h;
						v++;
						char m=g[v];
					}
				}
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(i==0 && j==0){
				if(a[i][j]==a[i+1][j])
					cout<<"1";
				else
					cout<<"0";
			}
			if(i==0 && j==1){
				if(x==y && 'm'=='n')
					cout<<"11";
				else if(x==y)
					cout<<"10";
				else
					cout<<"00";
			}

		}
	}
	if('m'-'n'==1 || 'm'-'n'==-1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
return 0;
}
