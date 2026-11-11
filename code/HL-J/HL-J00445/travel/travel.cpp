#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	string c1,s1,c2,s2,a[5]="0";
	bool f1=0,f2=0,f3=0;
	cin>>c1>>s1>>c2>>s2;
	freopen("travel.in","r",stdin);
	freopen("treavel.out","w",stdout);
	if(c1==c2){
		a[0]="1";
		f1=1;	
	}
	if(f1==1){
	
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]="1";
			f2=1;
		}
	
	if(f2==1){
		if(s1[2]=='C'&&s2[2]<s1[2]){
				a[2]="1";
				f3=1;
		}
		else if(s1[2]=='D'&&s2[2]>s1[2]){
				a[2]="1";
				f3=1;
		}
		else if(s1[2]=='A'&&s2[2]>'A'&&s2[2]<'C'){
			a[2]="1";
			f3=1;
		}
		else if(s1[2]=='B'&&s2[2]<'C'){
			a[2]="1";
			f3=1;
		}
	}
	
	}
	if(f3==1){
	
		if(abs(s1[2]-s2[2])==1){
			a[3]="1";
		}
	}		
		
	
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
