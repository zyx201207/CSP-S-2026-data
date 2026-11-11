#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=1;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			f1=0;
			break;
		}
	}
	if(f1==0){
		cout<<"0000\n";
		return 0;
	}
	bool f2=1;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			f2=0;
			break;
		}
	}
	if(f2==0){
		cout<<"1000\n";
		return 0;
	}
	if((s1[s1.size()-1]<='C'&&s2[s2.size()-1]>='D')||(s1[s1.size()-1]>='D'&&s2[s2.size()-1]<='C')){
		cout<<"1100\n";
		return 0;
	}
	if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1){
		cout<<"1111\n";
		return 0;
	}else{
		cout<<"1110\n";
		return 0;
	}
}
