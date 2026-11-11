#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char a[4],b[4],c[4],d[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if((int(a[0]-'0')*10+int(a[1]-'0'))==(int(c[0]-'0')*10+int(c[1]-'0'))){
		cout<<1;
	}else{
		cout<<"0000";return 0;
	}
	if((int(b[0]-'0')*10+int(b[1]-'0'))==(int(d[0]-'0')*10+int(d[1]-'0'))){
		cout<<1;
	}else{
		cout<<"000";return 0;
	}
	if(('D'==b[2]||b[2]=='F')&&('D'==d[2]||d[2]=='F')){
		cout<<11;return 0;
	}else if(((b[2]=='C')||(b[2])=='D')&&((d[2]=='C')||(d[2])=='D')){
		cout<<"00";return 0;
	}else if(('A'<=b[2]&&b[2]<='C')&&('A'<=d[2]&&d[2]<='C')){
		cout<<1;
		if(abs(int(b[2])-int(d[2]))==1){
			cout<<1;return 0;
		}else{
			cout<<0;return 0;
		}
	}else{
		cout<<"00";return 0;
	}
	return 0;
}
