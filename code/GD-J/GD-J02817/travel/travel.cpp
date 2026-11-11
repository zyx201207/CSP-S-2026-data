#include <bits/stdc++.h>
using namespace std;
namespace lty{
	int c1=0,c3=0;
	string c2="",c4="";
	int ans1=0,ans2=0,ans3=0,ans4=0;
	bool chef(char f1,char f2){
		if((f1=='F'&&f2=='D')||(f2=='F'&&f1=='D')){
			return true;
		}
		if(abs(f1-f2)==1&&(f1!='D'&&f2!='D')){
			return true;
		}
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>lty::c1>>lty::c2>>lty::c3>>lty::c4;
	//cout<<lty::c1<<" "<<lty::c2<<" "<<lty::c3<<" "<<lty::c4;
	//cout<<lty::c2[0]<<lty::c2[1]<<lty::c4[0]<<02 02B 02 01Alty::c4[1]<<endl;
	if(lty::c1==lty::c3){
		lty::ans1=1;
		cout<<1;
		if(lty::c2[0]==lty::c4[0]&&lty::c2[1]==lty::c4[1]){
			lty::ans2=1;
			cout<<1;
			if(((lty::c2[2]<='C'&&lty::c2[2]>='A')&&(lty::c4[2]<='C'&&lty::c4[2]>='A'))||((lty::c4[2]<='F'&&lty::c4[2]>='D')&&(lty::c2[2]<='F'&&lty::c2[2]>='D'))){
				lty::ans3=1;
				cout<<1;
				if(lty::chef(lty::c2[2],lty::c4[2])){
					lty::ans4=1;
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
