#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);		
	cin>>n;
	cin>>a;
	cin>>m;
	cin>>b;
	
	if(n==m){
		cout<<1;
		if(a[0]==b[0]){
			if(a[1]==b[1]){
				cout<<1;
				if(a[2]+b[2]<=133){
					cout<<1;
					if(b[2]-a[2]==1){
						cout<<1;
						return 0;
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else{
				cout<<"000";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
