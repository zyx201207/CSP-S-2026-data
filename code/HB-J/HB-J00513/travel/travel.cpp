#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)f1=1;
    if(f1&&s1[0]==s2[0]&&s1[1]==s2[1])f2=1;
    long long h1=0,h2=0;
    if(s1[2]>='A'&&s1[2]<='C'){
		h1=1;
	}
	if(s2[2]>='A'&&s2[2]<='C'){
		h2=1;
	}
	//cout<<h1<<" "<<h2;
    if((f1&&f2)&&h1==h2){
		f3=1;
	}
	int an1=int(s1[2]),an2=int(s2[2]);
	if((f1&&f2&&f3)&&(an1+an2==1||an1-an2==-1))f4=1;
	cout<<f1<<f2<<f3<<f4;
    return 0;
}
