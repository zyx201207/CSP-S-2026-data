#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool f[4]={0,0,0,0};
	if(c1==c2){
		f[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f[1]=1;
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
				f[2]=1;
				char i=min(s1[2],s2[2]),a=max(s1[2],s2[2]);
				if(i=='D'&&a=='F'||a-i==1)f[3]=1;
			}
		}
	}
	cout << f[0] << f[1] << f[2] << f[3];
	return 0;
}
