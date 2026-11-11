#include<bits/stdc++.h> 
using namespace std;
int c_1,c_2,a,b,c,d;
string s_1,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		a=1;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			b=1;
			if(s_1[2]<'D'&&s_2[2]<'D'){
				c=1;
				int cha=s_1[2]-s_2[2];
				if(cha==1||cha==-1){
					d=1;
				}
				else{
					d=0;
				}
			}
			else if(s_1[2]>'C'&&s_2[2]>'C'){
				c=1;
				d=1;
			}
			else{
				c=0;
				d=0;
			}
		}
		else{
			b=0;
			c=0;
			d=0;
		}
	}
	else{
		a=0;
		b=0;
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
