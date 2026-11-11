#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans_1,ans_2,ans_3,ans_4;
string c_1,c_2,c_3,c_4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>c_2>>c_3>>c_4;
	if(c_1[0]==c_3[0]&&c_1[1]==c_3[1]) ans_1=1;
	if(c_2[0]==c_4[0]&&c_2[1]==c_4[1]&&ans_1==1) ans_2=1;
	if(((c_2[2]<='C'&&c_4[2]<='C')||(c_2[2]>'C'&&c_4[2]>'C'))&&ans_2==1) ans_3=1;
	if(abs(c_2[2]-c_4[2])==1&&ans_3==1) ans_4=1;
	cout<<ans_1<<ans_2<<ans_3<<ans_4;
	return 0;
}

