#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int wh(int x){
	if(x<=2)return 1;
	return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int p1=(s1[0]-'0')*10+s1[1]-'0';
    int p2=(s2[0]-'0')*10+s2[1]-'0';
    int w1=s1[2]-'A',w2=s2[2]-'A';
    if(s1[2]=='F')w1=4;
    if(s2[2]=='F')w2=4;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2&&p1==p2)cout<<1;
    else cout<<0;
    if(c1==c2&&p1==p2&&wh(w1)==wh(w2))cout<<1;
    else cout<<0;
    if(c1==c2&&p1==p2&&wh(w1)==wh(w2)&&abs(w1-w2)==1)cout<<1;
    else cout<<0;
	return 0;
}

