#include<bits/stdc++.h>
using namespace std;
int s[4]={0,0,0,0},i;
char b[10],d[10];
char mid[10]={'A','B','C','D','F'};
string a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c&&(a!="01"&&a!="16")){
		s[0]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			s[1]=1;
			if((b[2]<=mid[2]&&d[2]<=mid[2])||(b[2]>=mid[3]&&d[2]>=mid[3])){
				s[2]=1;
				if(b[2]==d[2]+'1'-'0'||b[2]==d[2]-'1'+'0'){
					s[3]=1;
				}
			}
		}	
	}	
	for(int i=0;i<4;i++){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
