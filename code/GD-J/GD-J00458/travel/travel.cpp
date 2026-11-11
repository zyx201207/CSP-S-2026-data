#include <bits/stdc++.h>
using namespace std;

char a1,a2,a3,b1,b2,b3;
int a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>a2>>a3>>b>>b1>>b2>>b3;
	if(a==b){
		if(int(a1)+int(a2)==int(b1)+int(b2)){
			if(int(a3)+int(b3)==131||int(a3)+int(b3)==132||int(a3)+int(b3)==137||int(a3)+int(b3)==133){
				if(int(a3)+int(b3)==131||int(a3)+int(b3)==133||int(a3)+int(b3)==137){
					cout<<1111;
				}else{
					cout<<1110;
					return 0;
				}
			}else{
				cout<<1100;
				return 0;
			}
		}else{
			cout<<1000;
			return 0;
		}
		
	}else{
		cout<<"0000";
	}
	
	
	
	return 0;	
} 
