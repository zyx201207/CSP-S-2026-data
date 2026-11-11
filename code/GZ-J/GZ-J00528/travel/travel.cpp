//GZ-J00528 陈文谦 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			cout<<1;
			if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>='D'&&c2[2]>='D')){
				cout<<1;
				if(abs(int(c1[2]-c2[2]))==1)cout<<1; else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	cout<<endl;
	return 0;
} 
