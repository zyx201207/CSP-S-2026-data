//GZ-J00585 李博煜 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=0,fl=0,fla=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	if(c1==c2){
		cout<<1;
		fl=1;
	}
	else cout<<0;
	if(fl==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		 cout<<1;
		f=1;
	}
	else cout<<0;
	if(f==1){
		if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
			cout<<1;
			fla=1;
		}
		else if(a>='D'&&a<='F'&&b>='D'&&b<='F'){
			cout<<1;
			fla=1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(fla==1){
		if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
			if(abs(int(a)-int(b))==1)cout<<1;
		}
		else if(a=='D'&&b=='F'||a=='F'&&b=='D')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
