#include<bits/stdc++.h>
using namespace std;
long long a[10010],n,m,h,l;
string s,d,f,g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s>>d>>f>>g;
    if(s!=f){
    	cout<<"0000";
	}else{
		string x=d.substr(0,2),y=g.substr(0,2);
		cout<<"1";
		if(x!=y){
			cout<<"000";
		}else{
			cout<<"1";
			x=d.substr(2,1),y=g.substr(2,1);
			if((x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="C"&&y=="B")||(x=="B"&&y=="C")||(x=="F"&&y=="D")||(x=="D"&&y=="F")||(x=="A"&&y=="C")||(x=="C"&&y=="A")){
				cout<<"1";
			}else{
				cout<<"0";
			}
			if((x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="C"&&y=="B")||(x=="B"&&y=="C")||(x=="F"&&y=="D")||(x=="D"&&y=="F")){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	return 0;
}
