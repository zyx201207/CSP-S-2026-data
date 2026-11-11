#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1,n2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			for(int i=0;i<5;i++){
				if(s1[2]=='A'+i){
					n1=i;
					if(i>2)n2=i+1;
				}
				if(s2[2]=='A'+i){
					n2=i;
					if(i>2)n2=i+1;
				}
			}
			if(n1<=2&&n2<=2){
				cout<<"1";
				if(n1+1==n2||n2+1==n1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				if(n1>2&&n2>2){
					cout<<"11";
				}else{	
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		}
	return 0;
}
