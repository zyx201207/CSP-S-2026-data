#include <bits/stdc++.h>
using namespace std;
int n,m;string a,b;
bool sanzuo(char cd){
	if(cd=='a'&&cd=='b'){
		return 1;
	}
	else if(cd=='c'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;bool tong;char c=a[2],d=b[2];
	if(n==m)    cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])    cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(sanzuo(c)==sanzuo(d))    cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if((c=='C'&&c=='D')&&(d=='C'&&d=='D')){
		cout<<"0";
		return 0;
	}
	else if(c-1==d-1+1||c+1==d-1+1)    cout<<"1";
	else{
		cout<<"0";
		return 0;
	}
}
