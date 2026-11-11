#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int n[4];
	string N[4];
	int p[4];
	for (int i=1;i<=2;i++){
		cin>>n[i];
		cin>>N[i];
	}
	string a="0ABCDF";
	for(int i=1;i<=2;i++){
		for (int j=1;j<=5;j++){
			if(N[i][2]==a[j]){
			    p[i]=j;
		    }
		}
	}
	if (n[1]==n[2]){
		cout <<"1";
		if (N[1][0]==N[2][0]&&N[1][1]==N[2][1]){
			cout <<"1";
			if ((p[1]<=3&&p[2]<=3)||(p[1]+p[2]==9)){
				cout <<"1";
				if((p[1]-p[2]==1)||(p[2]-p[1]==1)){
					cout <<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout <<"00";
				return 0;
			}
		}
		else{
			cout <<"000";
		}
	}
	else{
		cout <<"0000";
		return 0;
	}
}
