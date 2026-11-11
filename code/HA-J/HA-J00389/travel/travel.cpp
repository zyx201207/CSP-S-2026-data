#include<bits/stdc++.h>
using namespace std;
int x,y;
string n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>n;
	cin>>y>>m;
	if(x==y){
		cout<<1;
		int a=(n[0]-'0')*10+(n[1]-'0'),b=(m[0]-'0')*10+(m[1]-'0');
		int c=n[2]-'A'+1,d=m[2]-'A'+1;
		if(a==b){
			cout<<1;
			if((c<=3 && d<=3) || (c>=4 && d>=4)){
				cout<<1;
				if(abs(c-d)==1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
