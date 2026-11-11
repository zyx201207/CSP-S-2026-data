//GZ-J00168 遵义市第四中学 陈律金
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			bool l=0,r=0;
			if(b[2]=='D'||b[2]=='F')l=1;
			if(d[2]=='D'||d[2]=='F')r=1;
			if(l==r){
				cout<<1;
				if(abs(b[2]-d[2])==1){
					if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))cout<<0;
					else cout<<1;
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
}
