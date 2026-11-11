#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c,c_1,s,s_1;
	cin>>c>>c_1>>s>>s_1;
	if(c!=s){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		int a=c_1[i]-'0',b=s_1[i]-'0';
		if(a!=b){
			cout<<"1000";
			return 0;
		}
	}
	int l=c_1[2]-'A'+1,l_2=s_1[2]-'A'+1;
	if((l==1||l==2||l==3)&&(l_2==4||l_2==5)){
		cout<<"1100";
		return 0;
	}
	if((l==4||l==5)&&(l_2==1||l_2==2||l_2==3)){
		cout<<"1100";
		return 0;
	}
	if((l==4&&l_2==5)||(l==5&&l_2==4)||(l==1&&l_2==2)||(l==2&&l_2==3)||(l==3&&l_2==2)||(l==2&&l_2==1)){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
