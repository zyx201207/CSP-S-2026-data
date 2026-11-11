#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
string s1,c1,s2,c2;
int fg,fg2,fg3,fg4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<0;
			fg=1;
			break;
		}
	}
	if(fg==0){
		cout<<1;
	}
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			cout<<0;
			fg2=1;
			break;
		}
	}
	if(fg2==0&&fg==0){
		cout<<1;
	}else if(fg2==0&&fg==1){
		cout<<0;
	}
	if(((c1[2]=='A'&&(c2[2]=='B'||c2[2]=='C'))||(c1[2]=='B'&&(c2[2]=='A'||c2[2]=='C'))||(c1[2]=='C'&&(c2[2]=='A'||c2[2]=='B'))||(c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D'))&&fg==0&&fg2==0){
		cout<<1;
		fg3=1;
	}
	if(fg3==0){
		cout<<0;
	}
	if(((c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&(c2[2]=='A'||c2[2]=='C'))||(c1[2]=='C'&&c2[2]=='B')||(c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D'))&&fg==0&&fg2==0){
		cout<<1;
		fg4=1;
	}
	if(fg4==0){
		cout<<0;
	}
	return 0;
}
