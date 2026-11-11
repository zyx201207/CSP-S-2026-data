#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n[5];
	int x,y = 0;
	string a;
	string b;
	cin>>n[1]>>a>>n[2]>>b;
	if(n[1]==n[2]){
		cout<<"1";
		x = a[0] + a[1];
		y = b[0] + b[1];
		if(x == y){
			cout<<"1";
			x,y = 0;
			x = int(a[2]);
			y = int(b[2]);
			if(x+y == 131||x+y == 132||x+y == 133||x+y == 138){
				cout<<"1";
				if(abs(x-y)==1){
					cout<<"1";
				}else{
					if(abs(x-y) == 2&&x+y == 138){
					    cout<<"1";
    				}else{
    					cout<<"0";
					}
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
