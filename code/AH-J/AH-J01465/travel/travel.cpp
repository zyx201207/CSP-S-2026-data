#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1;
	int r2,x2;
	char r3,x3;
	cin>>r1>>r2>>r3>>x1>>x2>>x3;
	if(r1==x1){
		if(r2==x2){
			if((r3<='C' && x3<='C') || (r3>='D' && x3>='D')){
				if(abs(r3-x3)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
