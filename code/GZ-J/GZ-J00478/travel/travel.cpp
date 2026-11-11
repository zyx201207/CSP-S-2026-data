//GZ-J00478 遵义航天高级中学 张煜皓
#include<bits/stdc++.h>
using namespace std; 
string stcut(string a,int st,int en){
	string ans="";
	for(int i=st;i<=en;i++) ans+=a[i];
	return ans;
}
char chan(string a){
	if(a.size()!=1){
		return '?';
	}return a[0];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		if(stcut(s1,0,1)!=stcut(s2,0,1)){
			cout<<"1000";
			return 0;
		}else{
			char seat1=chan(stcut(s1,2,2)),seat2=chan(stcut(s2,2,2));
			if(seat1=='C'&&seat2=='D'){
				cout<<"1100";
				return 0;
			}else if(seat1=='D'&&seat2=='C'){
				cout<<"1100";
				return 0;
			}else{
				if(abs((int)seat1-(int)seat2)!=1){
					if((seat1=='D'&&seat2=='F')||(seat1=='F'&&seat2=='D')){
						cout<<"1111";
						return 0;
					}
					cout<<"1110";
					return 0;
				}else{
					cout<<"1111";
					return 0;
				}
			}
		}
	}
	return 0;
}

