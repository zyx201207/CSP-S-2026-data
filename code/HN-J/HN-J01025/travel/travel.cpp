#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3],r2,x2;
int r,x,r1,x1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>s1>>x>>s2;
	if(r!=x){
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	else{
		cout<<1;
		r1=int(s1[0]-'0')*10+int(s1[1]-'0');
		x1=int(s2[0]-'0')*10+int(s2[1]-'0');
		if(r1!=x1){
			cout<<0<<0<<0<<endl;
			return 0;
		}
		else{
			cout<<1;
			r2=s1[2];
			x2=s2[2];
			if(r2<='C'&&x2<='C'){
				cout<<1;
				if(abs(r2-x2)==1){
					cout<<1<<endl;
					return 0;
				}
				else{
					cout<<0<<endl;
					return 0;
				}
			}
			else if(r2>'C'&&x2>'C'){
				cout<<1<<1<<endl;
				return 0;
			}
			else{
				cout<<0<<0<<endl;
				return 0;
			}
		}
	}
	return 0;
} 
