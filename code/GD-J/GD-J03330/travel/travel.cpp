#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	char a1[2],b1[3],a2[2],b2[3];
	cin>>a1>>b1>>a2>>b2;
	if(a1[0]==a2[0]&&a1[1]==a2[1]){
		cout<<"1 ";
		if(b1[0]==b2[0]&&b1[1]==b2[1]){
			cout<<"1 "; 
			if(b1[2]<'D'&&b2[2]<'D'){
				cout<<"1 ";
				if(abs(b1[2]-b2[2])==1){
					cout<<"1";
				}
				else{
					cout<<0;
				}
			}
			else if(b1[2]>='D'&&b2[2]>='D'){
				cout<<"1 1";
			}
			else{
				cout<<"0 0";
			}
		}
		else{
			cout<<"0 0 0";
		}
	}
	else{
		cout<<"0 0 0 0";
	}
}

