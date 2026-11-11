#include<bits/stdc++.h>
using namespace std;
string R,r,X,x;
int l=4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R>>r>>X>>x;
	if(R==X) {
		cout<<1;
		l--;
		if (r[0]==x[0]&&r[1]==x[1]) 
		{
			cout<<1;
			l--;	
			if((r[2]>='A'&&r[2]<='c'&&x[2]>='A'&&x[2]<='C')||(r[2]>='E'&&r[2]<='F'&&x[2]>='E'&&x[2]<='F')){
				cout<<1;
				l--;
				if((r[2]==x[2]+1||r[2]==x[2]-1)||(x[2]==r[2]+1||x[2]==r[2]-1)){
					cout<<1;
					l--;
				}
				else for(int i=1;i<=l;i++) cout<<0;
			}
			else for(int i=1;i<=l;i++) cout<<0;
		}
		else for(int i=1;i<=l;i++) cout<<0;
	}
	else {
		for(int i=1;i<=l;i++) cout<<0;
	}
	return 0;
} 
