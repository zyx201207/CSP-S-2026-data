#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int chang=s1.size()-1;
	if(c1==c2){
		cout<<"1";
		bool q=1;
		for(int i=0;i<chang;i++){
			if(s1[i]!=s2[i]) q=0;
		}
		if(q){
			cout<<"1";
			if(s1[chang]<='C' && s2[chang]<='C'){
				cout<<"1";
				if(abs(s1[chang]-s2[chang])==1) cout<<"1";
				else cout<<"0";
			}else if(s1[chang]>='D' && s2[chang]>='D') cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

