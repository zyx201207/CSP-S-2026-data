#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string C1,C2;
	int a,b;
	char c,d;
	cin.tie(0);
	cin>>C1>>a>>c>>C2>>b>>d;
	if(C1==C2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a==b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='E')&&(d=='D'||d=='E'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(c==d-1||c==d+1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
