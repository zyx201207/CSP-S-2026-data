#include<bits/stdc++.h>
using namespace std;
string x1,x2;
string y,z;
string a,c,b,d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<3;i++){
		if(i==0||i==1){
			x1+=b[i];
		}else{
			y=b[i];
		}
	}
	for(int i=0;i<3;i++){
		if(i==0||i==1){
			x2+=d[i];
		}else{
			z=d[i];
		}
	}
	if(a==c){
		cout<<1;
		if(x1==x2){
			cout<<1;
			if(y=="D"&&z=="F"){
				cout<<1;
			}else if(y=="C"&&z=="B"){
				cout<<1;
			}else if(y=="B"&&z=="A"){
				cout<<1;
			}else if(y=="A"&&z=="C"){
				cout<<1;
			}else if(y=="F"&&z=="D"){
				cout<<1;
			}else if(y=="B"&&z=="C"){
				cout<<1;
			}else if(y=="A"&&z=="B"){
				cout<<1;
			}else if(y=="C"&&z=="A"){
				cout<<1;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	if(y=="D"&&z=="F"){
		cout<<1;
	}else if(y=="C"&&z=="B"){
		cout<<1;
	}else if(y=="B"&&z=="A"){
		cout<<1;
	}else if(y=="F"&&z=="D"){
		cout<<1;
	}else if(y=="B"&&z=="C"){
		cout<<1;
	}else if(y=="A"&&z=="B"){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
