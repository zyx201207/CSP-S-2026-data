#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
int d[maxn][maxn][maxn];
bool ch(int se,int sr){
	if((se+1==sr)||(se==sr+1))return true;
	if(((se==3)&&(sr==5))||((se==5)&&(sr==3)))return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cf,cs,sf,ss;
	cin>>cf>>sf>>cs>>ss;
	int nu=(sf[0]-'0')*10+(sf[1]-'0');
	int nv=(ss[0]-'0')*10+(ss[1]-'0');
		char so=sf[2]-'A',st=ss[2]-'A';
	if(cf==cs){
		cout<<'1';
		if(nu==nv){
		    cout<<'1';
		    if(((so>=0&&so<=2)&&(st>=0&&st<=2))||((so>=3&&so<=5)&&(st>=3&&st<=5))){
		    	cout<<'1';
		    	if(ch(so,st))cout<<'1';
		    	else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
}
