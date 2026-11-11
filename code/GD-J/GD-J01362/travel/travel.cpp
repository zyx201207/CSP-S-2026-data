#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,a,c2,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>c2>>b;
	if(c1==c2){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			char x=a[2],y=b[2];
			if(((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))||((x=='D'||x=='F')&&(y=='D'||y=='F'))){
				cout<<1;
				if((x=='A'&&y=='C')||(x=='C'&&y=='A')){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
}
