#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,s2,c2;
int nbr1,nbr2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	nbr1=s1[2]-'A';
	nbr2=s2[2]-'A';
	if(c1==c2){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			if(nbr2<=2 && nbr1<=2){
				if(nbr2-1==nbr1 || nbr1-1==nbr2)printf("1111");
				else printf("1110");
			}else if(nbr2>2 && nbr1>2){
				printf("1111");
			}else printf("1100");
		}else printf("1000");
	}else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

