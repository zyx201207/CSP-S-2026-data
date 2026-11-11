#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int turn(char m){
	if(m=='A') return 1;
	if(m=='B') return 2;
	if(m=='C') return 3;
	if(m=='D') return 4;
	if(m=='F') return 5; 
}
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else{
		cout<<1;
		bool t=1;
		for(int i=0;i<2;i++){
			if(b[i]!=d[i]) t=0;
		}
		if(t==0){
			cout<<0<<0<<0;
			return 0;
		} 
		else{
			cout<<1;
			char x1=turn(b[2]),x2=turn(d[2]);
			if(x1<=3&&x2<=3||x1>=4&&x2>=4){
				cout<<1;
				int maxv=max(x1,x2),he=x1+x2,minv=he-maxv;
				if(maxv-minv==1) cout<<1;
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<0<<0;
				return 0;
			} 
		}
	}
	return 0;
}
