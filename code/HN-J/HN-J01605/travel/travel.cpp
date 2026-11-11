#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2,sum=0,n1,n2;
	string a1,a2;
	cin>>c1>>a1>>c2>>a2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(a1[i]==a2[i]){
	   			sum++;
			}
		}
		if(sum==2){
			cout<<"1"; 
		}else{
			cout<<"000";
			return 0;
		}
		n1=(int)a1[2];
		n2=(int)a2[2];
		if(n1<=67&&n2<=67){
			cout<<"1";
			if(n1-n2==1||n2-n1==1){
				cout<<"1";
			}else cout<<"0";
		}else if(n1>=68&&n2>=68){
			
			cout<<"11";
		}else cout<<"00";
	}else cout<<"0000";
	return 0;
} 
