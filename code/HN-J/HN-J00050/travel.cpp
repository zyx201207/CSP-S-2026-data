#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;//a代表小R的车厢号，b代表小R的座位号，c代表小x的车厢号，d代表小x的座位号 
	int x,y;
	string e,f;
	cin>>a>>x>>b>>c>>y>>d;
	if(a==c){
        cout<<"1";//是否在同一节车厢 
    	}
    	        else{
        	cout<<"0000";//如不在直接输出 
        	return 0;
		    } 
    if((a==c)and(x==y)){
    	cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	cout<<"10";
    	return 0;
	} 
