#include <bits/stdc++.h>
using namespace std;
int c1,c2,a[5];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
	}else{
		a[1]=0;
	}
	if(s1[1]==s2[1] && s1[2]==s2[2] && a[1]==1){
		a[2]=1;
	} else{
		a[2]=0;
	}
	if((s1[3]-'A'<3 && s2[3]-'A'<3)||(s1[3]-'A'>=3 && s2[3]-'A'>=3) && a[1]==a[2]==1)
	{
		a[3]=1;
	}else{
		a[3]=0;
	}
	if(a[1]==a[2]==a[3]==1 && (s1[3]-s2[3]==1 ||s1[3]-s2[3]==-1))
	{
		a[4]=1;
	}else{
		a[4]=0;
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
