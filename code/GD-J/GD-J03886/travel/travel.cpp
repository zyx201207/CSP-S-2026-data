#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string g,f;
	int ca,db,c,d,h,j;
	cin>>c>>ca;
	cin>>g;
	cin>>d>>db;
	cin>>f;
	if(c==d){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(ca==db){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(g=="F" && f=="D" || g=="D" && f=="F"){
		cout<<1;
	}else{
		if(g=="C" && f=="A" || g=="A" && f=="C"){
			cout<<1;
		}else{
			if(g=="B" && f=="A" || g=="A" && f=="B"){
				cout<<1;
			}else{
				if(g=="B" && f=="C" || g=="C" && f=="B"){
					cout<<1;
				}else{
					cout<<0;
					cout<<0;
					return 0;
				}
			}
		}
	}
	if(g=="F" && f=="D" || g=="D" && f=="F"){
		cout<<1;
	}else{
		if(g=="B" && f=="A" || g=="A" && f=="B"){
			cout<<1;
		}else{
			if(g=="B" && f=="C" || g=="C" && f=="B"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
} //àÅ ·ÇÈËÔÕ´úÂë 
