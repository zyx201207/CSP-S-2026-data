//GZ-J00197   遵义市第四中学	代铭轩 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
/*输入的第一行包含四个字符串c1, s1, c2, s2，
分别表示小R 的车票上的车厢号、座位号，
以及小X 的车票上的车厢号、座位号。*/
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){//两张车票对应的座位是否在同一节车厢；
		if(s1[0]==s2[0]&&s1[1]==s2[1]){//. 两张车票对应的座位是否在同一节车厢的同一排；
			//. 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					goto A;
				}else{
					cout<<"1100";return 0;
				}
			}else{
				if(s2[2]=='D'||s2[2]=='F'){
					goto A;
					A:
						//两张车票对应的座位是否相邻
						if((char)s1[2]==(char)s2[2]+1||(char)s1[2]==(char)s2[2]-1){
							cout<<"1111";return 0;
						}else{
							cout<<"1110";return 0;
						}
				}else{
					cout<<"1100";return 0;
				}
			}
		}else{
			cout<<"1000";return 0;
		}
	}else{
		cout<<"0000";return 0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
