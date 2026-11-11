#include<bits/stdc++.h>
using namespace std;
string cR,sR,cX,sX;//c³µÏá,s×ùÎ» 
bool ans[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cR>>sR>>cX>>sX;
	if(cR == cX){
		ans[0]=1;	
		if(sR[0]==sX[0]&&sR[1]==sX[1]){
			ans[1]=1;
			if((sR[2]>='D'&& sX[2]>='D')||(sR[2]<='C'&& sX[2]<='C')){
				ans[2]=1;
				if((sR[2]>='D'&& sX[2]>='D')||((sR[2]<='C'&& sX[2]<='C')&&abs(sR[2]-sX[2])==1)){
					ans[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++)cout<<ans[i];
	return 0;
}
