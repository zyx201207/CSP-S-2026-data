#include<bits/stdc++.h>

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	std::string s1,s2,s3,s4;
	std::cin>>s1>>s2>>s3>>s4;
	std::cout<<(s1==s3);

	std::cout<<(s1==s3 and
		s2[0]==s4[0] and s2[1]==s4[1]);

	std::cout<<(s1==s3 and
		s2[0]==s4[0] and s2[1]==s4[1] and(
		(s2[2]=='A' and s4[2]=='B') or
		(s2[2]=='A' and s4[2]=='C') or
		(s2[2]=='B' and s4[2]=='C') or
		(s2[2]=='D' and s4[2]=='F') or
		(s2[2]=='B' and s4[2]=='A') or
		(s2[2]=='C' and s4[2]=='A') or
		(s2[2]=='C' and s4[2]=='B') or
		(s2[2]=='F' and s4[2]=='D')));

	std::cout<<(s1==s3 and
		s2[0]==s4[0] and s2[1]==s4[1] and(
		(s2[2]=='A' and s4[2]=='B') or
		(s2[2]=='B' and s4[2]=='C') or
		(s2[2]=='D' and s4[2]=='F') or
		(s2[2]=='B' and s4[2]=='A') or
		(s2[2]=='C' and s4[2]=='B') or
		(s2[2]=='F' and s4[2]=='D')));


	return 0;
}
