#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],c2[3],c3[2],c4[3];
	int sum=4;
	for(int i=0;i<4;i++){
		if(i==0){
			cin>>c1[0]>>c1[1];
		}
		if(i==1){
			cin>>c2[0]>>c2[1]>>c2[2];
		}
		if(i==2){
			cin>>c3[0]>>c3[1];
		}
		if(i==3){
			cin>>c4[0]>>c4[1]>>c4[2];
		}
	}
	int n1=(c1[0]-'0')*10;
	int n2=(c1[1]-'0');
	int n=n1+n2;
	int m1=(c3[0]-'0')*10;
	int m2=(c3[1]-'0');
	int m=m1+m2;
	int x1=(c2[0]-'0')*10;
	int x2=(c2[1]-'0');
	int x=x1+x2;
	int y1=(c4[0]-'0')*10;
	int y2=(c4[1]-'0');
	int y=y1+y2;
	if(n==m){
		if(n>1&&n<16||n==17){
			cout<<1;
			sum--;
		}
		if(x==y&&x<=18&&x>=1){
			cout<<1;
			sum--;
			if(c2[2]>='A'&&c2[2]<='F'&&c2[2]!='E'){
				if(c4[2]>='A'&&c4[2]<='F'&&c4[2]!='E'){
					if(c2[2]!=c4[2]){
						cout<<1;
						sum--;
						if(c2[2]=='D'&&c4[2]=='F'){
							cout<<1;
							sum--;
						}
						if(c2[2]=='F'&&c4[2]=='D'){
							cout<<1;
							sum--;
						}
						if(c2[2]=='A'&&c4[2]=='B'){
							cout<<1;
							sum--;
						}
						if(c2[2]=='B'&&c4[2]=='A'){
							cout<<1;
							sum--;
						}
						if(c2[2]=='C'&&c4[2]=='B'){
							cout<<1;
							sum--;
						}
						if(c2[2]=='B'&&c4[2]=='C'){
							cout<<1;
							sum--;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<sum;i++){
		cout<<0;
	}
	return 0;
}
