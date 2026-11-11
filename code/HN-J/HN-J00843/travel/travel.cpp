#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int t[6],l1=1,l2=2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f=true;
	for(int i=0; i<=l1; i++){
		if(c1[i]!=c2[i]) f=false;
	}
	if(f){
		t[1]=1;
		for(int i=0; i<l2; i++){
			if(s1[i]!=s2[i]) f=false;
		}
		if(f){
			t[2]=1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) t[3]=1;
			else{
				t[3]=0; t[4]=0;
			}
			if(t[3]==1&&(s1[2]+1==s2[2] || s1[2]-1==s2[2])&&((s1[2]!='C' && s2[2]!='D')||(s2[2]!='C' && s1[2]!='D'))) t[4]=1;
		}
		else{
			t[2]=0; t[3]=0; t[4]=0;
		}
	}
	else{
		t[1]=0; t[2]=0; t[3]=0; t[4]=0;
	}
	for(int i=1; i<=4; i++) cout<<t[i];
	return 0;
} 
