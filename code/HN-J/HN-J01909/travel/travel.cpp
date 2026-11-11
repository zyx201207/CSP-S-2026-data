#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cn,cm,i,n,m;
bool bl[4];
string sn,sm;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cn>>sn>>cm>>sm;
	if (cn==cm) {
		bl[0]=1;
		if (sn[0]==sm[0]&&sn[1]==sm[1]) {
			bl[1]=1;
			if (sn[2]-'A'<3&&sm[2]-'A'<3) {
				bl[2]=1;
				if (sn[2]+1==sm[2]||sn[2]-1==sm[2]) bl[3]=1;
			}
		}
	}
	for (i=0;i<4;++i) cout<<bl[i];
	return 0;
}
