//GZ-J00247，秦泽锦玥，安顺开发区长水大洋实验学校 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int o[10];

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)o[1]=1;
	else o[1]=0;
	if(o[1]!=0){
			for(int i=1;i<=2;i++){
		s1[i]-'0';
		s2[i]-'0';
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])o[2]=1;
	else o[2]=0;
	if(o[2]!=0){
			int b=int(s1[2]),c=int(s2[2]);
	if(b<=67 && c<=67)o[3]=1;
	else if(b>67 && c>67)o[3]=1;
	else o[3]=0;
	if(b<=67 && c<=67){
		if(b+1==c or b-1==c)o[4]=1;
		else o[4]=0;
	}
	else if(b>67 && c>67){
		if(b+2==c or b-2==c)o[4]=1;
		else o[4]=0;
	}
	else{
		o[4]=0;
	}
	}
	else{
		o[3]=0;
		o[4]=0;
	}
	}
	else{
		o[2]=0;
		o[3]=0;
		o[4]=0;
	}
	
	for(int i=1;i<=4;i++){
		o[i]+='0';
		char p=char(o[i]);
		cout<<p;
	}
	return 0;
}
