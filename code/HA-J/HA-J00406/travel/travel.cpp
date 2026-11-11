#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[2]={0},b[3]={0},c[2]={0},d[3]={0},y=' ',z=' ';
	cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>c[0]>>c[1]>>d[0]>>d[1]>>d[2];
	int s[4]={0};
	if(a[0]==c[0]&&a[1]==c[1]){
		s[0]=1;
	}
	else{
		s[0]=0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a[0]==c[0]&&a[1]==c[1]){
		s[1]=1;
		}
	else{
		s[1]=0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
	    switch(b[2]){
			case'A':if(d[2]=='B'){
				s[2]+=1;
				s[3]+=1;
			}
			else if(d[2]=='C'){
				s[2]+=1;
			}
			else{
				s[2]=0;
				s[3]=0;
			}
				break;
			case'B':if(d[2]=='A'||'C'){
				s[2]+=1;
				s[3]+=1;
			}
			else{
				s[2]=0;
				s[3]=0;
			}
				break;
            case'C':if(d[2]=='B'){
				s[2]+=1;
				s[3]+=1;
			}
			else if(d[2]=='A'){
				s[2]+=1;
			}
			else{
				s[2]=0;
				s[3]=0;
			}
				break;
			case'D':if(d[2]=='E'){
				s[2]+=1;
				s[3]+=1;}
				else{
					s[2]=0;
					s[3]=0;
				}
				break;
			case'E':if(d[2]=='D'){
				s[2]+=1;
				s[3]+=1;}
				else{s[2]=0;s[3]=0;
				}
				break;
			}
	}
    for(int i=0;i<=3;i++){
    	printf("%d",s[i]);
	}
	return 0;
}
