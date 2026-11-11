#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int b1,b2,d1,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		b1=1;
	}else if(b[2]=='D'||b[2]=='F'){
		b2=1;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		d1=1;
	}else if(d[2]=='D'||d[2]=='F'){
		d2=1;
	}
	if(a[1]==c[1]&&a[0]==c[0]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(b1==1&&d1==1){
				cout<<1;
				if(b[2]=='B'||d[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(b2==1&&d2==1){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
			
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
