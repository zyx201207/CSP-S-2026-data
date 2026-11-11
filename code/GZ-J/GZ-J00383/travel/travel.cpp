//GZ-J00383 邓智豪 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int tc1=stoi(c1),tc2=stoi(c2);
	if(tc1==tc2){
		printf("%d",1);
		int ts1=stoi(s1.substr(0,2)),ts2=stoi(s2.substr(0,2));
		if(ts1==ts2){
			printf("%d",1);
			char tts1=s1[2],tts2=s2[2];
			if((tts1>='D' and tts2>='D') or (tts1<='C' and tts2<='C')){
				printf("%d",1);
				if(tts1-tts2==1 or tts2-tts1==1){
					printf("%s\n","1");
				}else{
					printf("%s\n","0");
				}
			}else{
				printf("%s\n","00");
			}
		}else{
			printf("%s\n","000");
		}
	}else{
		printf("%s\n","0000");
	}
	return 0;
}
