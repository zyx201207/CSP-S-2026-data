#include<iostream>
using namespace std;
char s1[5] ,s2[5];
string c1,c2;
int  ans = 0,sum = 0,same =0,together = 0;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(c1 == c2){
		ans = 1;
      cout<<"1";
	}else{
		cout<<"0";		
	}
	for(int i = 0;i <= 1;i ++){
	if(s1[i] == s2[i]){
		sum++;
	   } 
	}
    if(((s1[2] >= 'A' && s1[2] <='C') && (s2[2] >= 'A' && s2[2] <='C')) || ((s1[2] == 'D' || s1[2] == 'F') &&(s2[2] == 'D' || s2[2] == 'F')) && (s1[2]!=s2[2]))
	{
		same = 1;
		if((s1[2] -1 == s2[2]) || (s1[2] +1 == s2[2])){
			together = 1;
		}
	}
	if(ans == 1 && sum == 2){
		cout<<"1";
		if(same == 1){
		cout<<"1";
		if(together == 1){
			cout<<"1";
		}else{
			cout<<"0";
		}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}

	return 0;
}
