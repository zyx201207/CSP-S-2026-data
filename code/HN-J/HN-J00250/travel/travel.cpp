#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s2,s1;
bool tc,tp,te,xl;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		tc=1;
		int ps1=s1[0]*10+s1[1],ps2=s2[0]*10+s2[1];
		if(ps1==ps2) {
			tp=1;
			bool flag=0,flag2=1;
			char zw1=s1[2],zw2=s2[2];
			if(zw1=='D'&&zw2=='F')flag=1;
			if(zw1=='F'&&zw2=='D')flag=1;
			if(zw1=='C'&&zw2=='A')flag=1;
			if(zw1=='A'&&zw2=='C')flag=1;
			if(zw1=='D'&&zw2=='C')flag2=0;
			if(zw1=='C'&&zw2=='D')flag2=0;
			if(int(zw1)-int(zw2)==1||int(zw1)-int(zw2)==-1||flag) {
				if(flag2) {
					te=1;
					if(zw1=='F'||zw2=='F')xl=1;

					if(zw1=='C'&&zw2=='A')xl=0;
					else {
						if(zw2=='C'&&zw1=='A')xl=0;
						else {
							xl=1;
						}
					}



				}
			}
		}
	}
	cout<<tc<<tp<<te<<xl<<"\n";
	return 0;
}

