#include <bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<'1';
	else cout<<'0';
	for(int i=0;i<1;i++){
        if(a1[i]==b1[i]) c++;
     }
	if(c==2) cout<<'1';
	else cout<<'0';
	if('A'<=a1[2]>='C'&& 'A'<=b1[2]>='C') cout<<'1';
	else if('D'<=a1[2]>='F'&& 'D'<=b1[2]>='F') cout<<"11";
	else cout<<"00";
	if(a1[2]==b1[2]-1||a1[2]==b1[2]+1) cout<<"1";
	return 0;
}
