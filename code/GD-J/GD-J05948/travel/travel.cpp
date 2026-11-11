#include<iostream>
using namespace std;
int n,m,v,w,a,b;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>v>>n>>x>>w>>m>>y;
	a=int(x);
	b=int(y);
	if(v!=w){
		cout<<"0000";
		return 0;
	}
	else if(n!=m){
		cout<<"1000";
		return 0;
	}
	else if(a+b!=135){
		if(b-a==1 || a-b==1){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}	
	}
	else cout<<"1100";	
	return 0;
} 
