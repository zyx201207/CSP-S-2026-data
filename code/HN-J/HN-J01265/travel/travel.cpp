#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("teavel.in","r",stdin);
	freopen("teavel.out","w",stdout);
	int n[100];
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	n[0]=a;
	n[1]=b;
	n[2]=c;
	n[3]=d;
	if(n[0]==n[2]&&n[0]!=1&&n[0]!=16){
		cout<<"1";
		if(n[1]==n[3]){
			cout<<"1";
			if(n[1]==n[3]){
				cout<<"00";
			}
			else{
				cout<<"1";
				if(n[1]-n[3]==1&&n[3]-n[1]==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(n[1]==n[3]){
		cout<<"1";
	}

	
	return 0;
}
