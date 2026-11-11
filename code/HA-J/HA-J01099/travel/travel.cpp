#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(r,cin,travel.in);
	freopen(w,cout,travel.out);
	char b[10];
	char b1[10];
	int a,a1;
	int h[4]={0,0,0,0};
	cin>>a>>b>>a1>>b1;
	if(a==a1){
		h[0]=1;
		if(b[0]==b1[0]){
			if(b[1]==b1[1]){
				h[1]=1;
				if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
					if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
						h[2]=1;
						if(b[2]=='B'||b[2]=='A'){
							if(b1[2]=='B'||b1[2]=='A'){
								h[3]=1;
							if(b[2]=='C'){
								if(b1[2]=='B'){
									h[2]=1;
								}
							}
					if(b[2]=='D'||b[2]=='F'){
					if(b1[2]=='D'||b1[2]=='F'){
						h[2]=1;
						h[3]=1;
					}
				}
				}}}}}}}
	for(int i=0;i<4;i++){
		cout<<h[i];
	}
	return 0;
}
