#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	int arr[4]={};
	if(a==c){
		arr[0]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			arr[1]=1;
			if(b[2]>'C'&&d[2]<'D'){		
			}
			else{
				if(d[2]>'C'&&d[2]<'D'){
				}	
				else{
					arr[2]=1;
					if(b[2]-d[2]==1||d[2]-b[2]==1){
						arr[3]=1;
					}
				}
			}
		}
	}
	cout << arr[0]<< arr[1]<< arr[2]<< arr[3];
	return 0;
}
