#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1;
	cin >> s1;
	cin >> c2;
	cin >> s2;
	string len1[3],len2[3];
	for(int i=0;i<3;i++){
		len1[i]=s1[i];
		len2[i]=s2[i];
	}
	int l[4] = {0,0,0,0};
	if(c1 == c2){
		l[0] = 1;
	}else if(s1[1] == s2[1]){
		l[1] = 1;
	}else if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'E' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'E') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'A')){
		l[2] = 1;
	}else if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'E' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'E') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'A')){
		l[3] = 1;
	}
}
