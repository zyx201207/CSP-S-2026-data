#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],s1[4],c2[3],s2[4];
	char a[5];
	int flag=0;
	for(int i=1;i<=5;i++) a[i]='0'; 
	for(int i=1;i<=2;i++) cin>>c1[i];
	for(int i=1;i<=3;i++) cin>>s1[i];
	for(int i=1;i<=2;i++) cin>>c2[i];
	for(int i=1;i<=3;i++) cin>>s2[i];
	for(int i=1;i<=2;i++){
		if(c1[i]!=c2[i]){
			flag=1;
			break;
		}
	}
	for(int i=1;i<=3;i++){
		if(s1[i]!=s2[i]){
			if(i<=2){
				flag=2;
				break;
			}
			else{
				if(s1[3]=='A'){
					if(s2[3]=='B') flag=5;
					else if(s2[3]=='C') flag=4;
					else flag=3;
				}
				else if(s1[3]=='B'){
					if(s2[3]=='A' || s2[3]=='C') flag=5;
					else flag=3;
				}
				else if(s1[3]=='C'){
					if(s2[3]=='B') flag=5;
					else if(s2[3]=='A') flag=4;
					else flag=3;
				}
				else if(s1[3]=='D'){
					if(s2[3]=='F') flag=5;
					else flag=3;
				}
				else if(s1[3]=='F'){
					if(s2[3]=='D') flag=5;
					else flag=3;
				}
			}
		}
	}
	for(int i=1;i<flag;i++) a[i]='1';
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
} 
