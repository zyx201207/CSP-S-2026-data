#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string x,y;
int m;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>x>>b>>d>>y;
	if(a!=1&&b!=1&&a!=16&&b!=16&&a==b){
		m=1;
		cout<<m;
		if(c==d){
			m=1;
			cout<<m;
			if(x<="C"&&y<="C"||x>"C"&&y>"C"){
				m=1;
				cout<<m;
				if(x=="A"&&y=="B"||x=="B"&&y=="A"||x=="B"&&y=="C"||x=="C"&&y=="B"||x=="D"&&y=="F"||x=="F"&&y=="D"){
					m=1;
					cout<<m;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}       
