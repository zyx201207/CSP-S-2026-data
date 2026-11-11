#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	else{
		int aa=(a[0]-48)*10+a[1]-48;
		int bb=(b[0]-48)*10+b[1]-48;
		if(aa!=bb){
			cout<<"1000";
			return 0;
		}
		else{
			if((a[2]<='C' && b[2]<='C') || (a[2]>='D' && b[2]>='D')){
				if(abs(a[2]-b[2])!=1){
					cout<<"1110";
					return 0;
				}
				else{
					cout<<"1111";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
	}
	return 0;
}
