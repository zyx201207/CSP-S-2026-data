#include<bits/stdc++.h> 
using namespace std;
char a[15],b[15],c[15],d[15];
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<=1;i++){
		if(a[i]!=c[i]) f=1;
	}
	if(f==0){
		cout<<1;
		for(int i=0;i<=1;i++){
			if(b[i]!=d[i]) f=1;
		}
		if(f==0){
			cout<<1;
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				cout<<1<<1;
			}
			else if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')){
				cout<<1;
				if(b[2]-d[2]==1||d[2]-b[2]==1){
					cout<<1;
				}
				else{
					cout<<0;
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
	return 0;
}
