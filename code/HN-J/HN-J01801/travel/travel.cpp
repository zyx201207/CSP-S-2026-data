#include<bits/stdc++.h>
using namespace std;
string Cr,Sr,Cx,Sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Cr>>Sr>>Cx>>Sx;
	if(Cr[0]==Cx[0]&&Cr[1]==Cx[1]){
		if(Sr[0]==Sx[0]&&Sr[1]==Sx[1]){
			if((Sr[2]<='C')==(Sx[2]<='C')){
				if(abs(Sr[2]-Sx[2])==1)
					cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
