#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char z1,z2;
bool w2,w22,w3,w33;
string a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	z1=s1[2],z2=s2[2];
//	cout<<z1<<" "<<z2;
	w2=(z1<'D'&&z2<'D');
	w22=(z2>'C'&&z1>'C');
	w3=(z1==z2+1&&z1!='D');
	w33=(z2==z1+1&&z2!='D');
	if(c1==c2)cout<<1;
	else cout<<0;
	a1=s1.substr(0,2);
	a2=s2.substr(0,2);
	if(c1==c2&&a1==a2)cout<<1;
	else cout<<0;
	
	if(c1==c2&&a1==a2&&(w2||w22)){
		cout<<1;
	}else cout<<0;
	
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&(w2||w22)&&(w3||w33)){
		cout<<1;
	}else cout<<0;

	return 0;
}
