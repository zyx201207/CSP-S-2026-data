#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
		 cout<<1;
		int d1=(s1[0]-'0')*10+(s1[1]-'0');
		int d2=(s2[0]-'0')*10+(s2[1]-'0');
		if(d1==d2){
			 cout<<1;
			 char z1=s1[2],z2=s2[2];
			if(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'){
				 cout<<1;
				 if(abs(z1-z2)==1) cout<<1;
				 else cout<<0;
			 }
			else if((z1=='F'||z1=='D')&&(z2=='F'||z2=='D')){
				 cout<<"11";
			 }
			else cout<<"00";
		 }else cout<<"000";
		 return 0;
	}
	cout<<"0000";
    return 0;
}
