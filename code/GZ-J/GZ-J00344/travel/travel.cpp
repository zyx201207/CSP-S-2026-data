//GZ-J00344  遵义市第十九中学 丁钧泽
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a2=0,b2=0;
	string a1,b1,s,c;
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		for(int i=0;i<a1.size()-1;i++){
			a2*=10;
			a2+=a1[i]-'0';
		}
		for(int i=0;i<b1.size()-1;i++){
			b2*=10;
			b2+=b1[i]-'0';
		}
		if(b2==a2){
			cout<<"1";
			for(int i=0;i<a1.size();i++){
				if(!(a1[i]>='0' && a1[i]<='9')){
					s=a1[i];
					break;
				}
			}
			for(int i=0;i<b1.size();i++){
				if(!(b1[i]>='0' && b1[i]<='9')){
					c=b1[i];
					break;
				}
			}
			if(s=="A" || s=="B" || s=="C"){
				if((c=="A" || c=="B" || c=="C") && c!=s){
					cout<<1;
					if((s=="A" && c=="B") || (s=="B" && c=="C")){
						cout<<"1";
						return 0;
					}else if((c=="A" && s=="B") || (c=="B" && s=="C")){
						cout<<"1";
						return 0;
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
					return 0;
				}
			}else if(s=="D" || s=="F"){
				if((c=="D" || c=="F") && c!=s){
					cout<<"11";
					return 0;
				}else{
					cout<<"00";
					return 0;
				}
			}
		}else{
			cout<<"000";
			cout<<endl<<a2<<" "<<b2;
			return 0;
		}
	}
	return 0;
} 

