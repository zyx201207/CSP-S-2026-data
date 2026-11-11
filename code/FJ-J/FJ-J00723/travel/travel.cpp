#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<"1";
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			cout<<"1";
			int aaa=0,bbb=0;
			if(aa[2]>='D'){
				aaa=1;
			}
			if(bb[2]>='D'){
				bbb=1;
			}
			if(aaa==1&&bbb==1){
				cout<<"11";
			}else if(aaa==0&&bbb==0){
				if((aa[2]-bb[2]==-1)||(aa[2]-bb[2]==1)){
					cout<<"11";
				}else{
					cout<<"10";
				}
			}else{
				cout<<"00";
			}
			
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
