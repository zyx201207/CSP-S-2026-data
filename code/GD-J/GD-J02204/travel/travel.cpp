#include<bits/stdc++.h>
using namespace std;
#define rd read()
const int BUF=1<<20;
char buf[BUF],*head=buf,*tail=buf;
char out[BUF];
int ops=0;
inline char gc(){
	if(head==tail)head=buf,tail=buf+fread(buf,1,BUF,stdin);
	return head==tail?0:*head++;
}
inline long long read() {
	int n=0,f=1;
	char c=gc();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;c=gc();
	}
	while('0'<=c&&c<='9')n=n*10+c-'0',c=gc();
	return n*f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string s3;
	string s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1])cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if(s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C')){
			cout<<1;
		}
		else if(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C')){
			cout<<1;
		}
		else if(s2[2]=='C'&&(s4[2]=='A'||s4[2]=='B')){
			cout<<1;
		}
		else if(s2[2]=='D'&&(s4[2]=='F')){
			cout<<1;
		}
		else if(s2[2]=='F'&&(s4[2]=='D')){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&
	   ((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C'))||(s2[2]=='C'&&s4[2]=='B')||
	   (s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D'))
	)cout<<1;
	else cout<<0;
	return 0;
}
