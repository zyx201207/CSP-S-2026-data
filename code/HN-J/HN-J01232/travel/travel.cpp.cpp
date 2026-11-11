#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		s[1]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			s[2]=1;
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&b[2]=='D'))){
				s[3]=1;
				if(abs(b[2]-d[2])==1){
					s[4]=1;
				}else{
					s[4]=0;
				}
			}else{
				s[3]=0;
			}
		}
		else{
			s[2]=0;
		}
	}else{
		s[1]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<s[i];
	}
	return 0;
} 
