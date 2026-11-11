//GZ-J00495 六盘水知见外国语学校 蔡昕清
#include<bits/stdc++.h>
using namespace std;
struct zh{
	int ab;
	char c;
};
int main(){
	int n[8]={0};
	int   cx1,cx2;
	zh zh1,zh2;
	cin>>cx1>>zh1.ab>>zh1.c;
	cin>>cx2>>zh2.ab>>zh2.c;
	if (cx1==cx2){
		n[0]=1;
		if (zh1.ab==zh2.ab){
			n[1]=1;
			if (zh1.c=='A'||zh1.c=='B'||zh1.c=='C'){
				if (zh2.c!='E'&&zh2.c!='D'){
					n[2]=1;
					if(zh2.c=='B'||zh1.c=='B'){
						n[3]=1;
					}
				}
			}
			else if (zh1.c=='D'||zh1.c=='E'){
				if (zh2.c!='A'&&zh2.c!='B'&&zh2.c!='C'){
					n[2]=1;
					n[3]=1;
				}
			}
		}
	}
	for (int i=0;i<4;i++){
		cout<<n[i];
	}
	
	 
	return 0;
}
 
