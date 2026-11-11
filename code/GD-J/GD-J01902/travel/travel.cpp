#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
		if((b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')){
			ans[1]='1';
			if((b[2]>='A' and b[2]<='C' and d[2]>='A' and d[2]<='C') or (b[2]>='D' and b[2]<='E' and d[2]>='D' and d[2]<='E')){
				ans[2]='1';
				if(abs(b[2]-d[2])==1)
					ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
