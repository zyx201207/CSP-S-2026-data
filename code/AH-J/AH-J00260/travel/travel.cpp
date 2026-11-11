#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=0,a2=0,b1=0,b2=0;
	for(int i=0;i<2;i++){
		a1=a1*10+(c1[i]-'0');
		a2=a2*10+(c2[i]-'0');
		b1=b1*10+(s1[i]-'0');
		b2=b2*10+(s2[i]-'0');
	}
	if(a1==a2){
		cout<<1;
		if(b1==b2){
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				cout<<1;
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<00;
				return 0;
			}
		}
		else{
			cout<<000;
			return 0;
		}
	}
	else{
		cout<<0000;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
