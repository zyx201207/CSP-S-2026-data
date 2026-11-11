#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	bool flag1=1;
	for(int i=0;i<2;i++){
		if(a1[i]!=b1[i]){
			flag1=0;
		}
	}
	bool flag2=1;
	for(int i=0;i<2;i++){
		if(a2[i]!=b2[i]){
			flag2=0;
		}
	}
	if(flag1==1){
		cout << 1;
		if(flag2==1){
			cout << 1;
			int a=a2[2]-'A';
			int b=b2[2]-'A';
			if((a<3&&b<3)||(a>=3&&b>=3)){
				cout << 1;
				if(a-1==b||a+1==b){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
