//GZ-J00531  КывужабЇ ЩЬ№Љаљ
#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
long long i,l,r;
bool t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t=true;
	for(i=0;i<=1;i++){
	if(c1[i]!=c2[i]){
	cout<<"0000"<<'\n';
	return 0;
	}
	}
	cout<<"1";
if(s1[0]==s2[0]&&s1[1]==s2[1]){
	cout<<"1";
	r=s1[2];l=s2[2];
	if((r>=65&&r<=67&&l>=65&&l<=67)||(r>=68&&r<=69&&l>=68&&l<=69)){
		cout<<"1";
		r=s1[2];l=s2[2];
		if(r-1==l||l-1==r){
			cout<<"1"<<'\n';
		}else{
			cout<<"0"<<'\n';
			return 0;
		}
	}else{
		cout<<"00"<<'\n';
		return 0;
	}
}else{
	cout<<"000"<<'\n';
	return 0;
}
	return 0;
}
