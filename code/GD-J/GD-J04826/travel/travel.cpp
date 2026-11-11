#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[2],b[3],c[2],d[3];
	for(int i=0;i<2;i++){
		cin>>a[i];
	}
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	for(int i=0;i<2;i++){
		cin>>c[i];
	}
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	bool x=1,y=1,z=1,u=1;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<0;
			x=0;
		}
	}
	if(x)cout<<1;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<0;
			y=0;
		}
	}if(y)cout<<1;
	if(b[2]<'D'&&d[2]<'D'||b[2]>'C'&&d[2]>'C')
		cout<<1;
	else
		cout<<0;
	if(b[2]-1==d[2]||b[2]+1==d[2])cout<<1;
	else{
		cout<<0;
	}
	return 0;
} 
