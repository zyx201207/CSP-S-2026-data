#include<iostream>
#include<string>

std::string c1,s1,c2,s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	std::cin>>c1>>s1>>c2>>s2;

	bool ok1,ok2,ok3,ok4;
	ok1=ok2=ok3=ok4=false;

	if(c1==c2)
		ok1=true;

	if(ok1 and s1[0]==s2[0] and s1[1]==s2[1])
		ok2=true;

	if(ok2) {
		if(s1[2]=='F' or s1[2]=='D') {
			if(s2[2]=='F' or s2[2]=='D') {
				ok3=true;
			} else {
				ok3=false;
			}
		} else {
			if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C') {
				ok3=true;
			} else {
				ok3=false;
			}
		}
	}

	if(ok3) {
		int vis[10]= {false};

		vis[s1[2]-'A'+1]=true;
		vis[s2[2]-'A'+1]=true;

		for(int i=1; i<5; ++i) {
			if(vis[i] and vis[i+1] and i!=3) {
				ok4=true;
				break;
			}
		}
	}

	printf(ok1?"1":"0");
	printf(ok2?"1":"0");
	printf(ok3?"1":"0");
	printf(ok4?"1":"0");

	return 0;
}
