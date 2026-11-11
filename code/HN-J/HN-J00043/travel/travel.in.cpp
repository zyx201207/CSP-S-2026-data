#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3];//小R车票上的车厢号、座位号，以及小X的车票上的车厢号、座位号
int c1,c2;
int ans1,ans2,ans3,ans4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2) ans1=1;
	if(ans1==1&&s1[0]==s2[0]&&s1[1]==s2[1]) ans2=1;
    if(ans2==1&&s1[2]=='A'&&s2[2]=='B') ans3=1;
    if(ans2==1&&s1[2]=='A'&&s2[2]=='C') ans3=1;
    if(ans2==1&&s1[2]=='B'&&s2[2]=='A') ans3=1;
    if(ans2==1&&s1[2]=='B'&&s2[2]=='C') ans3=1;
    if(ans2==1&&s1[2]=='C'&&s2[2]=='A') ans3=1;
    if(ans2==1&&s1[2]=='C'&&s2[2]=='B') ans3=1;
    if(ans2==1&&s1[2]=='D'&&s2[2]=='F') ans3=1;
    if(ans2==1&&s1[2]=='F'&&s2[2]=='D') ans3=1;
	if(ans3==1&&s2[2]-s1[2]==1) ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
