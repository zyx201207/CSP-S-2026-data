#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==b){
		cout<<"1";
		if(b[0]==d[0]||b[1]==d[1]){
			cout<<"1";
			if(b[2]+=1==d[2]){
				cout<<"1";
			}else{
				cout<<"00";
			}
		}else{
		}
	}cout<<"1111";
		return 0;
}
