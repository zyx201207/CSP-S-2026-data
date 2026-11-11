#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	} 
	else{
		string a,b;
		a=s1[0]+s1[1],b=s2[0]+s2[1];
		if(a!=b){
			cout<<"1000"<<endl;
			return 0;
		}
		else{
			char t1=s1[2],t2=s2[2];
			if((t1<'D'&&t2>='D')||(t1>='D'&&t2<'D')){
				cout<<"1100"<<endl;
				return 0;
			}
			else{
				int t=t1-t2;
				if(abs(t)!=1)cout<<"1110"<<endl;
				else cout<<"1111"<<endl;
			}
		}
	}
	return 0;
}
