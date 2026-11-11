//GZ-J00063 毕节七星关东辰实验学校 吴拼 
#include<iostream>
#include<string>
using namespace std;
void solve(){
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c[0]==cc[0] && c[1]==cc[1]){
		printf("1");
		if(s[0]==ss[0] && s[1]==ss[1]){
			printf("1");
			if(s[2]<='C' && ss[2]<='C'){
				printf("1");
				if(s[2]=='B' || ss[2]=='B'){
					printf("1");
					return;
				}else{
					printf("0");
					return;
				}
			}else if(s[2]>='D' && ss[2]>='D'){
				printf("11");
				return;
			}else{
				printf("00");
				return;
			}
		}else{
			printf("000");
			return;
		}
	}else{
		printf("0000");
		return;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
