#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int a1=0,a2=0,a3=0,a4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c) a1=1; 
	if(b[0]==d[0]&&b[1]==d[1]) a2=1;
	if(int(b[2])<=67&&int(d[2])<=67||int(b[2])>67&&int(d[2])>67) a3=1;
	if(abs(int(b[2])-int(d[2]))==1) a4=1;
	if(b[2]=='D'&&d[2]=='F'||d[2]=='D'&&b[2]=='F') a4=1;
	if(a1==0) cout<<"0000";
	else if(a2==0) cout<<a1<<"000";
	else if(a3==0) cout<<a1<<a2<<"00";
    else cout<<a1<<a2<<a3<<a4;
	return 0;
}
