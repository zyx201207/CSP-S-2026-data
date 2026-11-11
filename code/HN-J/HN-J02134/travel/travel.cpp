#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string a[10];
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	if(a[2][2]=='F'){
		a[2][2]='E';
	}
	if(a[4][2]=='F'){
		a[4][2]='E';
	}
	x=int(a[2][2]-'A');
	y=int(a[4][2]-'A');
	if(a[1]==a[3]){
		cout<<1;
		if(a[2][0]==a[4][0]&&a[2][1]==a[4][1]){
			cout<<1;
			if(x<=2&&x>=0&&y<=2&&y>=0){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(x<=4&&x>=3&&y<=4&&y>=3){
				cout<<11;
			}
			else{
				cout<<0<<0;;
				return 0;
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		
	}
	return 0;
} 
