//GZ-J00576 黄思翔 六盘水市第二十四中学
#include <bits/stdc++.h>
using namespace std;
string s[8];
char a[5],b[5],c[5],d[5];
int sum,num;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c[i];
	}
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	for(int i=1;i<=2;i++){
		if(a[i]==c[i]){
			sum++;
		}
		if(b[i]==d[i]){
			num++;
		}
	}
	if(sum==2){
		s[1]="1";
		if(num==2){
			s[2]="1";
			if(b[3]=='A'||b[3]=='B'||b[3]=='C'){
				if(d[3]=='A'||d[3]=='B'||d[3]=='C'){
					s[3]="1";
					if(b[3]=='A'&&d[3]=='B'){
						s[4]="1";
					}else if(d[3]=='A'&&b[3]=='B'){
						s[4]="1";
					}else if(b[3]=='B'&&d[3]=='C'){
						s[4]="1";
					}else if(d[3]=='B'&&b[3]=='C'){
						s[4]="1";
					}else{
						s[4]="0";
					}
				}else{
					s[3]="0";
					s[4]="0";
				}
			}else if(b[3]=='D'||b[3]=='F'){
				if(d[3]=='D'||d[3]=='F'){
					s[3]="1";
					s[4]="1";
				}
			}else{
				s[3]="0";
				s[4]="0";
			}
		}else{
			s[2]="0";
			s[3]="0";
			s[4]="0";
		}
	}else{
		s[1]="0";
		s[2]="0";
		s[3]="0";
		s[4]="0";
	}
	for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
}
