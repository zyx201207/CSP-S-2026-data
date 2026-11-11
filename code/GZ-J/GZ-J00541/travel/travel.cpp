//GZ-J00541 兴义市弘毅中学 刘桐瑞
#include<bits/stdc++.h>
using namespace std;
double s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
cout<<1;
if(s1-'A'==s2-'A') cout<<1;
else cout<<0;
if(s1<='C'&&s2<='C'||s1>='D'&&s2>='D') cout<<1;
else cout<<0;
if(s1<='C'&&s2<='C'||s1>='D'&&s2>='D'){
if(s1-s2==1||s2-s1==1) cout<<1;
}
else cout<<0;
}
else cout<<"0000";
	return 0;
} 
