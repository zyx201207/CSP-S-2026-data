#include<bits/stdc++.h>
using namespace std;
int c[2],s[2],x[2],d=0;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a>>b;
		c[i]=(a[0]-'0')*10+a[1]-'0';	
		s[i]=(b[0]-'0')*10+b[1]-'0';
		x[i]=b[2]-'A'+1;
		
	}
	if(c[1]==c[2])cout<<1;
	else if(c[1]!=c[2])cout<<0;
	if(s[1]==s[2]&&c[1]==c[2])cout<<1;
	else cout<<0;
	if((s[1]==s[2])&&((x[1]>=4&&x[2]>=4)||(x[1]<=3&&x[2]<=3))&&c[1]==c[2])
	cout<<1;
	else cout<<0;
	if(abs(s[1]-s[2])==1)
	d++;
	if(abs(x[1]-x[2])==1)
	d++;
	if(c[1]==c[2]&&d==1&&((x[1]>=4&&x[2]>=4)||(x[1]<=3&&x[2]<=3)))
	cout<<1;
	else cout<<0;
	return 0;
}
