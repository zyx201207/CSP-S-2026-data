#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	int q,p;
	cin>>a>>q>>b>>c>>p>>d;
	if(a==c){
	 	cout<<1;
	}else{
	 	cout<<0;
	}
	if(a==c&&q==p){
	 	cout<<1;
	}else{
	 	cout<<0;
	}
	if(a==c&&q==p&&((b=="E"&&d=="D"||b=="D"&&d=="E")||(b=="A"&&d=="B"||b=="B"&&d=="A")||(b=="C"&&d=="A"||b=="A"&&d=="C")||(b=="C"&&d=="B"||b=="B"&&d=="C"))){
	 	cout<<1;
	}else{
	 	cout<<0;
	}
	if(a==c&&q==p&&((b=="E"&&d=="D"||b=="D"&&d=="E")||(b=="A"&&d=="B"||b=="B"&&d=="A")||(b=="C"&&d=="B"||b=="B"&&d=="C"))){
	 	cout<<1;
	}else{
	 	cout<<0;
	}
	return 0;
} 
