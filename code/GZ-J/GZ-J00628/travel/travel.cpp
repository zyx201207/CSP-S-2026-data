//GZ-J00628，邱光伍，贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
char a[2],b[3],c[2],d[3];
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++) cin>>a[i];
	for(int i=1;i<=3;i++) cin>>b[i];
	for(int i=1;i<=2;i++) cin>>c[i];
	for(int i=1;i<=3;i++) cin>>d[i];
	if(a[1]==c[1]&&a[2]==c[2]) cout<<1;
	if(b[1]==d[1]&&b[2]==d[2]) cout<<1;
	if(b[3]=='A'||b[3]=='B'||b[3]=='C'){
		if(d[3]=='A'||d[3]=='B'||d[3]=='C') cout<<1;
		else cout<<0;
	}
	else{
		if(d[3]=='D'||d[3]=='F') cout<<1;
		else cout<<0;
	}
	if(b[3]!='F'){
		if(abs(d[3]-b[3])==1) cout<<1;
		else cout<<0;
	}
	else{
		 if(d[3]=='D') cout<<1;
		else cout<<0;
	}
	return 0;
} 
