//GZ-J00699 Ëï³çÏö 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n_R,n_X;
	string che_R,che_X;
	cin>>n_R;
	getchar();
	cin>>che_R;
	cin>>n_X;
	getchar();
	cin>>che_X;
	
	if(n_R==n_X){
		cout<<"1";
		if(che_R[0]==che_X[0]&&che_R[1]==che_X[1]){
			cout<<"1";
			if((che_R[2]>='A'&&che_R[2]<='C')&&(che_X[2]>='A'&&che_X[2]<='C')||(che_R[2]>='D'&&che_R[2]<='F')&&(che_X[2]>='D'&&che_X[2]<='F')){
				cout<<"1";
				if(abs(che_R[2]-che_X[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
}

