//GZ-J00721 贵阳市第三实验中学 刘子轩 
#include<bits/stdc++.h>
using namespace std;
string t1c,t1s,t2c,t2s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>t1c>>t1s>>t2c>>t2s;
	if(t1c==t2c){
		printf("1");
		if(t1s[0]==t2s[0]&&t1s[1]==t2s[1]){
			printf("1");
			//cout<<t1q[1]<<" "<<t2q[1]<<endl;
			if((t1s[2]>='A'&&t1s[2]<='C'&&t2s[2]>='A'&&t2s[2]<='C')||(t1s[2]>='D'&&t1s[2]<='F'&&t2s[2]>='D'&&t2s[2]<='F')){
				printf("1");
				if(abs(t1s[2]-t2s[2])==1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
				return 0;
			}
		}else{
			printf("000");
			return 0;
		}
	}else{
		printf("0000");
	}
	return 0;	
}

