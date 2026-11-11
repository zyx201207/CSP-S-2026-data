#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string p,q;
	for(int i=0;i<s1.size()-1;i++){
		p+=s1[i];
	}
	for(int i=0;i<s2.size()-1;i++){
		q+=s2[i];
	}
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	} 
	else{
		if(p!=q){
			cout<<"1000"<<endl;
			return 0;
		}
		else{
			if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')){
				cout<<"1100"<<endl;
				return 0;
			}
			else{
				if(((s1[2]+1!=s2[2])&&(s2[2]+1!=s1[2]))&&(s1[2]<='C'&&s2[2]<='C')){
					cout<<"1110"<<endl;
					return 0;
				}
				else cout<<"1111"<<endl;
			}
		}
	}
	return 0;
} 
