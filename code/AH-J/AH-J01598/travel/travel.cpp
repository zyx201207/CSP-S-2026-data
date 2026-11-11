#include<bits/stdc++.h> 
using namespace std;
char c1n1,c1n2,s1n1,s1n2,s1n3,c2n1,c2n2,s2n1,s2n2,s2n3;
int k1,k2,k3,k4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1n1>>c1n2>>s1n1>>s1n2>>s1n3>>c2n1>>c2n2>>s2n1>>s2n2>>s2n3;
	//cout<<k<<endl;
	//cin>>k>>k>>k;
	//cout<<k<<endl;
	if((c1n1==c2n1)&&(c1n2==c2n2))
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}	
	if((s1n1==s2n1)&&(s1n2==s2n2))
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}	
	int c1=max(s1n3-'A',s2n3-'A'),c2=min(s2n3-'A',s1n3-'A');
	//cout<<endl<<c1<<" "<<c2<<endl;
	if(c1<=2&&c2<=2)
		cout<<1;
	else if(c1>2&&c2>2)
		cout<<1;
	else{
		cout<<"00";
		return 0;		
	}
	if((c1-c2)==1)
		cout<<1;
	else
		cout<<0;	
	return 0;
}
//A B C| D E
