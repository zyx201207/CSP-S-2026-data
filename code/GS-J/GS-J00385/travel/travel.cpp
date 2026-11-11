#include<bits/stdc++.h>
using namespace std;
int main(){
	feropen("travel.in","r",stdin);
	feropen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	int c1,c2;
	string s1,s2,v="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		v[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			v[1]='1';
			if(s1[3]<='C'&&s2[3]<='C'||s1[3]>='D'&&s2[3]>='D'){
				v[2]='1';
				if(s1[3]-s2[3]==1||int(s1[3])-int(s2[3])==-1){
					v[3]='1';
				}
			}
		}
	}
	cout<<v;
return 0;
}
