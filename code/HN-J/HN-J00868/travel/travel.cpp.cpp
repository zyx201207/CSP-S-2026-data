#include<bits/stdc++.h> 
using namespace std;
char a[3],b[9],c[3],d[9],e1[2],e2[2];
bool jk=0,po=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	e1[1]=b[3];
	for(int i=1;i<=2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	e2[1]=d[3];
	for(int i=1;i<=2;i++){
		if(a[i]==c[i]){
			jk=1;
		}else{
			jk=0;
		}
	}
	if(!jk){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		for(int i=1;i<=2;i++){
			if(b[i]==d[i]){
				po=1;
			}else{
				po=0;
			}
		}
		if(!po){
			cout<<"000";return 0;
		}else{
			cout<<1;
			int e3=e1[1]-64;
			int e4=e2[1]-64;
			if(e3+1==e4||e4+1==e3){
				if(e3!=3){
					if(e3!=4){
						cout<<11;
						return 0;
					}else{
						cout<<"00";
						return 0;
					}
				}else{
					cout<<"00";
					return 0;
				}
			}else{
				if(e3+2==e4||e4+2==e3){
					if(e3==1||e4==1){
						cout<<10;return 0;
					}else{
						cout<<"00";return 0;
					}
				}else{
					cout<<"00";return 0;
				}
			}
		}
	}
	return 0;
}
