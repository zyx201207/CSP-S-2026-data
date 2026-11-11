#include<bits/stdc++.h>
using namespace std;
bool f_1,f_2,f_3,f_4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,c_2,s_1,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		f_1=1;
		if(s_1[0]==s_2[0]&&s_2[1]==s_1[1]){
			f_2=1;
			if(s_1[2]>='D'&&s_2[2]>='D'){
				f_3=1;
				if(s_1[2]==s_2[2]+1||s_1[2]==s_2[2]-1)
					f_4=1;//
			}
			if(s_1[2]<='C'&&s_2[2]<='C'){
				f_3=1;
				if(s_1[2]==s_2[2]+1||s_1[2]==s_2[2]-1)
					f_4=1;//
			}
		}
	}
	cout<<f_1<<f_2<<f_3<<f_4;
	return 0;
}
