#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string l1,l2;
	l1+=s1[0],l2+=s2[0];
	l1+=s1[1],l2+=s2[1];
	char w1=s1[2],w2=s2[2];
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(l1!=l2){
			cout<<"000";
		}else{
			cout<<"1";
			if( !( ( (w1=='D'&&w2=='F') || (w1=='F'&&w2=='D') ) || (w1!='D'&&w1!='F'&&w2!='D'&&w2!='F') ) ){
				cout<<"00";
			}else{
				cout<<"1";
				if(( (w1=='D'&&w2=='F') || (w1=='F'&&w2=='D') ) || (w1=='A'&&w2=='B') || (w1=='B'&&w2=='A') || (w1=='C'&&w2=='B') || (w1=='B'&&w2=='C')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
