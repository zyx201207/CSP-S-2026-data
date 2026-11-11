#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=(((s1[0]-'0')*10+(s1[1]-'0'))==((s2[0]-'0')*10+(s2[1]-'0')));
	bool g=((s1[2]-'A')<3),k=(s2[2]-'A'<3);
	if(c1==c2){
		if(f){
			if(g==k){
				if(k==0||k==1&&abs(s2[2]-s1[2])==1)cout<<1111;
				else cout<<1110;
			}else cout<<1100;
		}else cout<<1000;
	}
	else cout<<"0000";
	return 0;
} 
