#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
int f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[0]>>c1[1]>>s1[0]>>s1[1]>>s1[2]>>c2[0]>>c2[1]>>s2[0]>>s2[1]>>s2[2];
	if(f&&c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	if(f&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	if(f&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	if(f&&abs(int(s1[2]-s2[2]))==1){
		cout<<f;
	}else{
		f=0;
		cout<<f;
	}
	return 0;
}
