#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
string sa1,sa2,sb1,sb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa1>>sa2>>sb1>>sb2;
	if(sa1==sb1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string str1=sa2.substr(0,2);
	string str2=sb2.substr(0,2);
	if(str1==str2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(sa2[2]=='F'){
		if(sb2[2]=='D'){
			cout<<11;return 0;
		}else{
			cout<<"00";return 0;
		}
	}else if(sa2[2]=='D'){
		if(sb2[2]=='F'){
			cout<<11;return 0;
		}else{
			cout<<"00";return 0;
		}
	}else if(sa2[2]=='C'){
		if(sb2[2]=='B'){
			cout<<11;return 0;
		}else if(sb2[2]=='A'){
			cout<<10;return 0;
		}else{
			cout<<"00";return 0;
		}
	}else if(sa2[2]=='B'){
		if(sb2[2]=='C'){
			cout<<11;return 0;
		}else if(sb2[2]=='A'){
			cout<<11;return 0;
		}else{
			cout<<"00";return 0;
		}
	}else{
		if(sb2[2]=='B'){
			cout<<11;return 0;
		}else if(sb2[2]=='C'){
			cout<<10;return 0;
		}else{
			cout<<"00";return 0;
		}
	}
	return 0;
}
