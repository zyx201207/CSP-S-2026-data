#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string p1;p1+=s1[0];p1+=s1[1];
		string p2;p2+=s2[0];p2+=s2[1];
		if(p1==p2){
			cout<<1;
			char z1=s1[2];
			char z2=s2[2];
			char t=z1;
			z1=min(z1,z2);
			z2=max(z2,t);
			if((z1=='A'&&z2=='B')||(z1=='A'&&z2=='C')||(z1=='B'&&z2=='C')||(z1=='D'&&z2=='F')){
				if((z1=='A'&&z2=='B')||(z1=='B'&&z2=='C')||(z1=='D'&&z2=='F')) cout<<11;
				else cout<<10;
			}
			else cout<<"00";
		}
		else cout<<"000";	
	}	
	else cout<<"0000";
	return 0;
}
