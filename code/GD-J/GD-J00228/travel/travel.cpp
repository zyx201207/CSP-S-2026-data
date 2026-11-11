#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2; string s1,s2;cin>>c1>>s1>>c2>>s2;
	bool fl=1;
	if(c1==c2) cout<<1;
	else {
		cout<<0;
		fl=0;
	}
	
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			fl=0;
		}
	}cout<<fl;
	int fl2=0;
	if(fl){
		if('A'<=s1[2] and 'C'>=s1[2] and 'A'<=s2[2] and 'C'>=s2[2]){
			fl2=1;
		}else if(s1[2]=='D' and s2[2]=='F'){
			fl2=2;
			cout<<11;
			return 0;
		}else if(s1[2]=='F' and s2[2]=='D'){
			fl2=2;
			cout<<11;
			return 0;
		}
	}//cout<<endl<<fl2<<endl;
	if(fl2==1){
		cout<<1;
		if(abs(s1[2]-s2[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}if(fl2==0){
		cout<<"00";
	}
	return 0;
} 
