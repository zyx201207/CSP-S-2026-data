#include <bits/stdc++.h>
using namespace std;
int a[4]={0,0,0,0};
string c_1,c_2,s_1,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		a[0]=1;
		if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
			a[1]=1;
			if((s_1[2]>='D'&&s_2[2]<='E'&&s_2[2]>='D'&&s_1[2]<='E')||(s_1[2]>='A'&&s_2[2]<='C'&&s_2[2]>='A'&&s_1[2]<='C')){
				a[2]=1;
				if(!(s_1[2]-'A'+s_2[2]-'A'==2)){
					a[3]=1;
				}
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
//	cout<<c_1<<" "<<c_2<<" "<<s_1<<" "<<s_2;<<" "
	return 0;
}
