#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct ch{
	string a,b;
}x,y;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x.a>>x.b>>y.a>>y.b;
	n=x.b[2];
	m=y.b[2];
	if(x.a==y.a){
		cout<<"1";
		if(x.b[0]==y.b[0]&&x.b[1]==y.b[1]){
			cout<<"1";
			if(((n-65)<=2&&(m-65)<=2)||((n-65)>=3&&(m-65)>=3)){
				cout<<"1";
				if((n-65)-(m-65)<=1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
