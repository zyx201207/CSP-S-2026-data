//GZ-t00611 北京师范大学贵阳附属中学 陆志嘉 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		int ant1=int(s1[0]-'0')*10+int(s1[1]-'0');
		int ant2=int(s2[0]-'0')*10+int(s2[1]-'0');
		char n1=s1[2];
		char n2=s2[2];
		char m1=min(n1,n2);
		char m2=max(n1,n2);
		
		if(ant1==ant2){
			cout<<1;
			if((n1!='C' && n2!='D') || (n2!='D' && n1!='D')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
		int mc1=min(ant1,ant2);
		int mc2=max(ant1,ant2);
		if((ant1==ant2 && (m1+1==m2 || (m1=='D' && m2=='F'))&& m1!='C' && m2!='D') || (n1==n2 && mc1+1==mc2)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
