#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,a1,c2,a2;
	string s,d;
	cin>>c1>>a1>>s>>c2>>a2>>d;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}if(a1==a2&&c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a1==a2&& c1==c2){
		if(a1==a2&&c1==c2&&s=="A"||s=="B"||s=="C"&&d=="A"||d=="B"||d=="C"||s=="F"||s=="D"&&d=="F"||d=="D"){
			if(s=="C"&& d=="D"||s=="D"&& d=="C")
				cout<<"0";
			else{
				cout<<"1";
			}
		}
	}else{
		cout<<"0";
	}
	if(a1==a2&& c1==c2){
		if(a1==a2&&s=="A"&&d=="B"||s=="B"&& d=="A" ||s=="B"&&d=="C"||s=="C"&& d=="B"||s=="F"&&d=="D"||s=="D"&& d=="F"){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
}
