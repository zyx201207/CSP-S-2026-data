#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long a,c;
	string b,d;
	bool f1=0,f2=0,f3=0;
	cin>>a>>b>>c>>d;
	
	if(a==c){
		cout<<1;
		f1=1;
	}else{
		cout<<0;
	}
	
	if(f1 && b[0]+b[1]==d[0]+d[1]){
		f2=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f2 && ( (b[2]=='D' && d[2]=='F') || (b[2]!='D' && d[2]!='F') )){
		f3=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f3 && ( (b[2]=='D' && d[2]=='F') || (d[2]=='D' && b[2]=='F') || (b[2]=='A' && d[2]=='B') || (d[2]=='A' && b[2]=='B') || (b[2]=='C' && d[2]=='B') || (d[2]=='B' && b[2]=='C'))){
		cout<<1;
	}else{
		cout<<0;
	}
}

























































