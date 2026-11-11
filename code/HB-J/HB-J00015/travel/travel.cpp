#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,d,e;
	cin>>a>>b;
	int c=(a-'0')*10+b-'0';
	cin>>a>>b>>d;
	int f=(a-'0')*10+b-'0';
	cin>>a>>b;
	int g=(a-'0')*10+b-'0';
	cin>>a>>b>>e;
	int h=(a-'0')*10+b-'0';
	if(c==g){
		cout<<1;
		if(f==h){
			cout<<1;
			if(d=='D'&&e=='F'||d=='F'&&e=='D'||d=='A'&&e=='B'||d=='A'&&e=='C'||d=='B'&&e=='A'||d=='B'&&e=='C'||d=='C'&&e=='A'||d=='C'&&e=='B'){
				cout<<1;
				if(d=='D'&&e=='F'||d=='F'&&e=='D'||d=='A'&&e=='B'||d=='B'&&e=='A'||d=='B'&&e=='C'||d=='C'&&e=='B') cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
