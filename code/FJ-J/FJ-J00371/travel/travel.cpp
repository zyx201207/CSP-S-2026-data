#include<bits/stdc++.h>
using namespace std;

const int MAXN=10;
const int side[5]={1,1,1,2,2};
char c1[MAXN],c2[MAXN],s1[MAXN],s2[MAXN];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%s%s%s%s",c1,s1,c2,s2);
	
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(side[s1[2]-'A']==side[s2[2]-'A']){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
