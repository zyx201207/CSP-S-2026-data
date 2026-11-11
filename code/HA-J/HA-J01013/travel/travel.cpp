#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2){
		a1=1;
		if((s2[0]-'0')*10+(s2[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
			a2=1;
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
				a3=1;
				if(int(s1[2])-int(s2[2])==1||int(s2[2])-int(s1[2])==1) a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}

