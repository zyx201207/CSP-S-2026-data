#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int l1,l2,l3,l4;
bool check(){
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			if (s2[l2-1]-'A'+1==i && s4[l4-1]-'A'+1==j){
				return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	l1=s1.size();
	l2=s2.size();
	l3=s3.size();
	l4=s4.size();
	int jl1=0,jl2=0;
	for (int i=0;i<l1;i++){
		jl1=jl1*10+(s1[i]-'0');
	}
	for (int i=0;i<l3;i++){
		jl2=jl2*10+(s3[i]-'0');
	}
	if (jl1!=jl2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	jl1=jl2=0;
	for (int i=0;i<l2-1;i++){
		jl1=jl1*10+(s2[i]-'0');
	}
	for (int i=0;i<l4-1;i++){
		jl2=jl2*10+(s4[i]-'0');
	}
	if (jl1!=jl2){
		cout<<"000";
	}else{
		cout<<"1";
		if (check()){
			cout<<"1";
			if (abs((s2[l2-1]-'A'+1)-(s4[l4-1]-'A'+1))==1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}
	
	
	return 0;
}