//GZ-J00674兴义市弘毅中学龙家仁
#include<bits/stdc++.h>
using namespace std;
string s,c,ss,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>s>>c>>ss>>cc;
	if(s==ss){
		cout<<1;
	}else {
		cout<<"0000";
		return 0;
	}
	if(c[0]==cc[0]&&c[1]==cc[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((c[2]>='A'&&c[2]<='C'&&cc[2]>='A'&&cc[2]<='C')||(c[2]>='D'&&c[2]<='F'&&cc[2]>='D'&&cc[2]<='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((c[2]=='A'&&cc[2]=='B')||(c[2]=='B'&&cc[2]=='A')||(c[2]=='B'&&cc[2]=='C')||(c[2]=='C'&&cc[2]=='B')||(c[2]=='F'&&cc[2]=='D')||(c[2]=='F'&&cc[2]=='D')){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
} 
