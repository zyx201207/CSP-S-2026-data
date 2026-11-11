#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>c>>m>>b>>d;
	if(n!=m){
		cout<<"0000"<<endl;return 0;
	}
	else cout<<"1";
	if(a!=b){
		cout<<"000"<<endl;return 0;
	}
	else cout<<"1";
	if((c<='C'&&d<='C')||(c>='D'&&d>='D')){
		cout<<"1";
	}
	else {cout<<"00"<<endl;return 0;}
	if(c-d==1||d-c==1)cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
