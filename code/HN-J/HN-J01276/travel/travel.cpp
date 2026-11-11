#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	
	bool f1;
	if(c1==c3)f1=1;
	else f1=0;
	
	bool f2=1;
	if(!f1)f2=0;
	else{
		for(int i=0;i<1;i++)
			if(c2[i]!=c4[i])f2=0;
	}
	
	bool f3;
	if(!f2)f3=0;
	else{
		char pr,px;
		if(c2[2]=='D'||c2[2]=='F')pr='r';
		else pr='l';
		if(c4[2]=='D'||c4[2]=='F')px='r';
		else px='l';
		if(pr==px)f3=1;
		else f3=0;
	}
	
	bool f4;
	if(!f3)f4=0;
	else
		if(c2[2]=='C'&&c4[2]=='D'||c4[2]=='C'&&c2[2]=='D')f4=0;
		else
			if(abs(c2[2]-c4[2])==1)f4=1;
			else f4=0;
			
	cout<<f1<<f2<<f3<<f4;
	return 0;
}

