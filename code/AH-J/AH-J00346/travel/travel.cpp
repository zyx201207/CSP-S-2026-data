#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,k1,k2;
long long cnt=0,ans=0;
string x,y;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		ans++;
	}else{
		cout<<"0";
	}
	k1=s1.substr(0,2);
	k2=s2.substr(0,2);
	if(k1==k2&&ans>0){
		cout<<"1";
		x=s1.substr(2,1);
		y=s2.substr(2,1);
		if(x=="A"){
			if(y=="B"||y=="C"){
				cout<<"1";
				cnt++;
			}else{
				cout<<"0";
			}
		}
		if(x=="B"){
			if(y=="A"||y=="C"){
				cout<<"1";
				cnt++;
			}else{
				cout<<"0";
			}
		}
		if(x=="C"){
			if(y=="A"||y=="B"){
				cout<<"1";
				cnt++;
			}else{
				cout<<"0";
			}
		}
		if(x=="D"){
			if(y=="F"){
				cout<<"1";
				cnt++;
			}else{
				cout<<"0";
			}
		}
		if(x=="F"){
			if(y=="D"){
				cout<<"1";
				cnt++;
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"00";
	}
	if(cnt>0){
		if((x=="A"&&y=="B")||(x=="B"&&y=="C")||(x=="D"&&y=="F")||(x=="F"&&y=="D")){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	
	return 0;
}
