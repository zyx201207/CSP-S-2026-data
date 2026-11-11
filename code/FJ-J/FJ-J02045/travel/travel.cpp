#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>c>>m>>b>>d;
	if(n==m){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if(a<=3&&b<=3||a>3&&b>3){
				cout<<"1";
				if(c+1==d||d+1==c||a>3&&b>3){
					cout<<"1";
				}else{
					cout<<"0";
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
