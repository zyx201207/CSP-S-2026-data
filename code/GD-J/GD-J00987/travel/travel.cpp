#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
long long n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	} 
	if(c1==c2){
		printf("%d",1);
		if(s1[0]==0){
			n1+=s1[1]-'0';
		}else{
			n1+=10+s1[1]-'0';
		}
		if(s2[0]==0){
			n2+=s2[1]-'0';
		}else{
			n2+=10+s2[1]-'0';
		}
		if(n1==n2){
			printf("%d",1);
			char a=s1[2],b=s2[2];
			if(a=='F'&&b=='D'||a=='D'&&b=='F'){
				printf("%d%d",1,1);
				return 0;
			}else if(a=='A'||a=='B'||a=='C'){
				if(b=='A'||b=='B'||b=='C'){
					printf("%d",1);
					if(a=='A'&&b=='B'||a=='B'&&b=='A'
					||a=='B'&&b=='C'||a=='C'&&b=='B'){
						printf("%d",1);
					}else{
						printf("%d",0);
					}
				}else{
					printf("%d%d",0,0);
					return 0;
				}
			} 
		}else{
			printf("%d%d%d",0,0,0);
			return 0;
		}
	}else{
		printf("%d%d%d%d",0,0,0,0);
		return 0;
	}
	return 0;
}