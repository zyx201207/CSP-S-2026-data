#include<bits/stdc++.h>
using namespace std;
string a[10005],b[10005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(a[2]==b[2]){
				cout<<1;
			}else{
				cout<<0;
			}
			if(a[3]=="A"&&b[3]=="B"||a[3]=="B"&&b[3]=="A"||a[3]=="B"&&b[3]=="C"||a[3]=="C"&&b[3]=="B"||a[3]=="A"&&b[3]=="C"||a[3]=="C"&&b[3]=="A"||a[3]=="D"&&b[3]=="F"||a[3]=="F"&&b[3]=="D"){
				cout<<1;
			}else{
				cout<<0<<a[3];
			}
			if(a[3]=="A"&&b[3]=="B"||a[3]=="B"&&b[3]=="A"||a[3]=="B"&&b[3]=="C"||a[3]=="C"&&b[3]=="B"||a[3]=="D"&&b[3]=="F"||a[3]=="F"&&b[3]=="D"){
				cout<<1;
			}else{
				cout<<0;
			}
			break;
		}
	}
	
	return 0;
} 
