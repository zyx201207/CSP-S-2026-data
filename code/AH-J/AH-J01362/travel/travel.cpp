#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char in01[4],in02[4];
int i,in1,in2;
bool ans1=0,ans2=0,ans3=0,ans4=0;
cin>>in1;
for(i=1;i<=3;i++)
{
	cin>>in01[i];
}
cin>>in2;
for(i=1;i<=3;i++)
{
	cin>>in02[i];
}
if(in1==in2)
{
	ans1=1;
}
else{
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
if(in01[1]==in02[1]){
	if(in01[2]==in02[2]){
		ans2=1;
	}
	else{
		cout<<ans1<<ans2<<ans3<<ans4;
	    return 0;
	}
}
else{
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
if(in01[3]=='A'||in01[3]=='B'||in01[3]=='C'){
	if(in02[3]=='A'||in02[3]=='B'||in02[3]=='C')
	ans3=1;
	else ans3=0;
}
else if(in01[3]=='D'||in01[3]=='F'){
	if(in02[3]=='D'||in02[3]=='F')
	ans3=1;
	else ans3=0;
}
if(in01[3]=='A'){
	if(in02[3]=='B')
		ans4=1;
}
else if(in01[3]=='B'){
	if(in02[3]=='A'||in02[3]=='C')
		ans4=1;
}
else if(in01[3]=='C'){
	if(in02[3]=='B')
		ans4=1;
}
else if(in01[3]=='D'||in01[3]=='F'){
	if(in02[3]=='F'||in02[3]=='D')
		ans4=1;
}

cout<<ans1<<ans2<<ans3<<ans4;
return 0;
}
