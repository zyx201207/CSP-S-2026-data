#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			if(s1[2]<='C'&&s2[2]<='C'){
				if(abs(s2[2]-s1[2])==1) cout<<1111<<endl;
				else cout<<1110<<endl;
			}else if(s1[2]>='D'&&s2[2]>='D') cout<<1111<<endl;
			else cout<<1100<<endl;
		}else cout<<1000<<endl;
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
