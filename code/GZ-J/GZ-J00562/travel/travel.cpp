//GZ-J00562，戚星汉，贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
int a,b; 
string x,y,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	c=x.substr(0,2);
	d=y.substr(0,2);
	if(c==d){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	x=x.substr(2,1);
	y=y.substr(2,1);
	if(x<="C"){
		if(y<="C"){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0; 
		}
	}
	if(x>="D"){
		if(y>="D"){
			cout<<"1";
		}
		else{
			cout<<"00";
			return 0; 
		}
	}
	if((x[0]+1==y[0]&&x!="C")||(y[0]+1==x[0]&&y!="C")){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
//肚子的全加易经备乃隆草饲了
