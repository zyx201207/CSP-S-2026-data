#include<bits/stdc++.h>
using namespace std;
int a[5]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}else{
		string a3="",b3="";
		a3+=a2[0]+a2[1],b3+=b2[0]+b2[1];
		char a4=a2[2],b4=b2[2];
		if(a3!=b3){
			cout<<"1000";
			return 0;
		}else{
			if(a[a4-'A']!=a[b4-'A']){
				cout<<"1100";
				return 0;
			}else{
				if(abs(a4-b4)==1){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	return 0;
	while(1);
}
