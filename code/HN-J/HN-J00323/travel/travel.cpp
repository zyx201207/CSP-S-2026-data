#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d,s="";
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		s=s+"1";
		if(b[0]+b[1]==d[0]+d[1]){
			s=s+"1";
			if(b[2]<='C'&&d[2]<='C' or b[2]>='D'&&b[2]>='F'){
				s=s+"1";
				if(abs(b[2]-d[2])==1) s=s+"1";
			}
		}
	}
	while(s.size()!=4) s=s+"0";
	cout<<s;
	return 0;
}
