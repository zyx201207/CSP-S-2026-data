#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c2[4],c4[4];
	string c1,c3;
	cin>>c1;
	for(int i=1;i<=3;++i)
	    cin>>c2[i];
	cin>>c3;
	for(int i=1;i<=3;++i)
	    cin>>c4[i];
	if(c1==c3){
		cout<<"1";
		if(c2[1]==c4[1]&&c2[2]==c4[2]){
			cout<<"1";
			if(c2[3]<='C'&&c4[3]>='D'){
				cout<<"00";
				return 0;
			}else if(c2[3]>='D'&&c4[3]<='C'){
				cout<<"00";
				return 0;
			}else{
				cout<<"1";
				if(c2[3]-c4[3]==1||c4[3]-c2[3]==1){cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
	    cout<<"0000";
	    return 0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
