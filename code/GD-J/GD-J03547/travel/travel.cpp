#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	if(!(a[0]==a[2])){
		cout<<"0000";
		return 0;
	}
	else{
		if(!(a[1][0]==a[3][0]&&a[1][1]==a[3][1])){
			cout<<"1000";
			return 0;
		}
		else{
			if(!(max(a[1][2],a[3][2])!='D')){
				cout<<"1100";
				return 0;
			}
			else{
				if(!(min(a[1][2],a[3][2])+1==max(a[1][2],a[3][2])||min(a[1][2],a[3][2])=='D'&&max(a[1][2],a[3][2])=='F')){
					cout<<"1110";
					return 0;
				}
				else{
					cout<<"1111";
				}
			}
		}
	}
	return 0;
} 
