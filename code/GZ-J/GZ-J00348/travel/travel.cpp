//GZ-J00348 遵义市第十二中学 张晋宁 
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		for(int i=0;i<=1;i++){
			if(b[i]!=d[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')||(b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F')){
			cout<<"1";
			if(int(b[2])-int(d[2])==1||int(b[2])-int(d[2])==-1){
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
	return 0;
}
