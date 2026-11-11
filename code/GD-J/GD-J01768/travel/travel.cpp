#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
	cout<<1;
			int k1=s1[2]-'A',k2=s2[2]-'A'; k1++;k2++;
			if(k1+k2==9 || k1+k2==3 || k1+k2==4 || (k1+k2==5 && k1!=4 && k2!=4)) {
	cout<<1;
	if(k1-k2==1||k2-k1==1){cout<<1;
	}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	
	
	return 0;
}
