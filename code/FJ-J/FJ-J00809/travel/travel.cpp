#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<"1";
    	int k1=0,k2=0,w1,w2;
    	for(int i=0;i<2;i++){
    		k1=k1*10+int(s1[i]-'0');
		}
		
		w1=int(s1[2]-'A'+1);
		
		
    	for(int i=0;i<2;i++){
    		k2=k2*10+int(s2[i]-'0');
		}
		
		w2=int(s2[2]-'A'+1);
		
		if(k1==k2){
			cout<<"1";
		}else{
			cout<<"0";
		}
		if(k1==k2&&((w1<=3&&w2<=3)||(w1>=4&&w2>=4))){
			cout<<"1";
		}else{
			cout<<"0";
		}
		if(abs(w1-w2)==1&&k1==k2
		&&((w1<=3&&w2<=3)||(w1>=4&&w2>=4))){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
/*
02 01C 02 01A
*/
