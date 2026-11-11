#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,d,e;
	char c,f;
	int s[10];
	cin>>a>>b>>c>>d>>e>>f;
	s[1]=0,s[2]=0,s[3]=0,s[4]=0;
	if(a==d){
		s[1]=1;
		if(b==e){
			s[2]=1;
			if((c<='C'&&f<='C')||(c>='D'&&f>='D')){
				s[3]=1;
				if((c-f==1)||(f-c==1)){
					s[4]=1;
				}else{
					s[4]=0;
				}
			}else{
				s[3]=0;
			}
		}else{
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
