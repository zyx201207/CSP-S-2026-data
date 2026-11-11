#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,a_a,b,b_b;
	cin>>a>>a_a>>b>>b_b;
	if(a!=b){
		cout <<"0000";
	}else{
		if(a_a[0]!=b_b[0]){
			cout <<"1000";
		}else if(a_a[1]!=b_b[1]){
			cout <<"1000";
		}else{
			if(a_a[2]>'C'&&b_b[2]>'C'){
				cout <<"1111";
			}else if((a_a[2]>'C'&&b_b[2]<'D')||(a_a[2]<'D'&&b_b[2]>'C')){
				cout<<"1100";
			}else{
				if(abs(a_a[2]-b_b[2])==1){
					cout <<"1111";
				}else{
					cout <<"1110";
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
