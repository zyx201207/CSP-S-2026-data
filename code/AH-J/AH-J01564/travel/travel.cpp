#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//treavel treavl
	int a,b;
	cin>>a>>b;
	char c;
	cin>>c;
	int d,e;
	cin>>d>>e;
	char f;
	cin>>f;
	if(a==d){
		cout<<1;
		if(b==e){
			cout<<1;
			int x,y;
			if(c>='A'&&c<='C')
				x=1;
			if(c>='D'&&c<='F')
				x=2;
			if(f>='A'&&f<='C')
				y=1;
			if(f>='D'&&f<='F')
				y=2;
			if(x==y){
				cout<<1;
				if(c==char(f-1)||c==char(f+1)||(c=='D'&&f=='F')||(c=='F'&&f=='D'))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}

