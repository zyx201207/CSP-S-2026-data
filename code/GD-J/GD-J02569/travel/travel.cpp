#include<bits/stdc++.h>
using namespace std;
struct travel{
	string xiang;
	string wei;
}a[3];
int main(){
	freopen("travel.in","r",stdin);
	freoprn("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i].xiang>>a[i].wei;
	}
	if(a[1].xiang==a[2].xiang){
		cout<<"1";
		if(a[1].wei[0]==a[2].wei[0]&&a[1].wei[1]==a[2].wei[1]){
			cout<<"1";
			if(((a[1].wei[2]>='A'&&a[1].wei[2]<='C')&&(a[2].wei[2]>='A'&&a[2].wei[2]<='C'))||((a[1].wei[2]>='D'&&a[1].wei[2]<='F')&&((a[2].wei[2]>='D'&&a[2].wei[2]<='F')))){
				cout<<"1";
				if((a[1].wei[2]!='A'&&a[2].wei[2])||(a[1].wei[2]!='C'&&a[2].wei[2]!='A')){
					cout<<"1";
				}else {
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
	return 0;
}
