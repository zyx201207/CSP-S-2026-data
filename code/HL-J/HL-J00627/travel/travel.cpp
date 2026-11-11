#include<bits/stdc++.h>
using namespace std;

int main(){
	int c1,s1,c2,s2;
	int t1,t2,t3,t4;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		t1=1;
	}else{
		t1=0;
	}
	if ((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')&&(s1[3]=='D'||s1[3]=='D'&&s1[3]=='F'||s1[3]=='F'){
		t2=1;
		t3=1;
	}else{
		t2=0;
		t3=0;
	}
	if(a[2]==a[2]-1){
		t4=1;
	}else{
		t4=0;
	}
	cout<<t1<<t2<<t3<<t4<<endl;

	return 0;
}
