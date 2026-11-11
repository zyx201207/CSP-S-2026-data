#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int f[4+25];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
		if(a==c) {
			f[1]=1;
		}
		else{
			f[1]=0;
		}
			if(f[1]==1&&(b[0]==d[0]&&b[1]==d[1])){
				f[2]=1;
				if((((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))))
			{
				f[3]=1;
				if(f[3]=1&&(abs(b[2]-d[2])==1))
		{
			f[4]=1;
		}
		else
		{
			f[4]=0;
		}
			}
			else
			{
				f[3]=0;
			}
				}
			else{
				f[2]=0;
			}
		cout<<f[1]<<f[2]<<f[3]<<f[4];
	return 0;
}
